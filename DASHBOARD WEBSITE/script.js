const body = document.querySelector("body"),
    sidebar = body.querySelector(".sidebar"),
    toggle = body.querySelector(".toggle");

//   bagian >
toggle.addEventListener("click", () => {
    sidebar.classList.toggle("close");
});

function showSection(id) {
    document.querySelectorAll('.section').forEach(sec => {
        sec.style.display = 'none';
    });
    document.getElementById(id).style.display = 'block';
}

// setup firebase
const firebaseConfig = {
    apiKey: "AIzaSyAcgOQlwG7nNT1ULe3OA_1PSN_j6ObFOQc",
    authDomain: "ta-agrolytics.firebaseapp.com",
    projectId: "ta-agrolytics",
    storageBucket: "ta-agrolytics.firebasestorage.app",
    messagingSenderId: "963533651324",
    appId: "1:963533651324:web:d095499fa9e0d8d3ff38f9",
    measurementId: "G-XLHC2P85B1"
};

firebase.initializeApp(firebaseConfig);
const db = firebase.firestore();

// bagian monitoring

let monitorMap = null;
let monitorMarker = null;
let currentSessionListener = null;
let currentSessionId = null;

function updateMap(lat, lng) {
    if (!monitorMap) {
        monitorMap = L.map("map-monitoring", {
            scrollWheelZoom: false
        }).setView([lat, lng], 15);

        monitorMap.on("click", function () {
            monitorMap.scrollWheelZoom.enable();
        });
        monitorMap.on("mouseout", function () {
            monitorMap.scrollWheelZoom.disable();
        });

        L.tileLayer("https://tile.openstreetmap.org/{z}/{x}/{y}.png", {
            maxZoom: 19,
            attribution: "© OpenStreetMap"
        }).addTo(monitorMap);
    }

    if (monitorMarker) {
        monitorMarker.setLatLng([lat, lng]);
    } else {
        monitorMarker = L.marker([lat, lng]).addTo(monitorMap);
    }

    monitorMarker.bindPopup(`<b>Lokasi Monitoring</b><br>Lat: ${lat}<br>Lng: ${lng}`).openPopup();
    monitorMap.setView([lat, lng], 15);
    monitorMap.invalidateSize();
}

function listenLatestSession() {
    db.collection("agrolytics_monitoring")
        .orderBy("startTime", "desc")
        .limit(1)
        .onSnapshot((sessionSnapshot) => {
            if (sessionSnapshot.empty) return;

            const sessionDoc = sessionSnapshot.docs[0];
            const sessionId = sessionDoc.id;
            const sessionData = sessionDoc.data();

            // update map dari lokasi sesi
            if (sessionData.location) {
                const lat = sessionData.location.latitude;
                const lng = sessionData.location.longitude;
                updateMap(lat, lng);
            }

            if (sessionId === currentSessionId) return;
            currentSessionId = sessionId;

            if (currentSessionListener) {
                currentSessionListener();
                currentSessionListener = null;
            }

            // listen data realtime
            currentSessionListener = db
                .collection("agrolytics_monitoring")
                .doc(sessionId)
                .collection("data")
                .orderBy("timestamp")
                .onSnapshot((dataSnapshot) => {
                    const dataSession = dataSnapshot.docs.map(doc => doc.data());
                    if (dataSession.length === 0) return;

                    showMonitoringChart(dataSession);

                    const last = dataSession[dataSession.length - 1];
                    document.getElementById("val-N").textContent = (last.nitrogen ?? "--") + " ppm";
                    document.getElementById("val-P").textContent = (last.phosphorus ?? "--") + " ppm";
                    document.getElementById("val-K").textContent = (last.potassium ?? "--") + " ppm";
                    document.getElementById("val-suhu").textContent = (last.temperature ?? "--") + " °C";
                    document.getElementById("val-kelembaban").textContent = (last.humidity ?? "--") + " %";
                    document.getElementById("val-ph").textContent = (last.ph ?? "--");
                    document.getElementById("val-ec").textContent = (last.ec ?? "--");

                    const timestamp = last.timestamp?.toDate(); // konversi Firestore Timestamp ke JS Date
                    const formatted = timestamp ? timestamp.toLocaleString("id-ID", {
                        day: "2-digit",
                        month: "2-digit",
                        year: "numeric",
                        hour: "2-digit",
                        minute: "2-digit",

                    }) : "--";
                    document.getElementById("last-update").textContent = formatted;
                });
        });
}

listenLatestSession();

// simpan semua instance chart
const charts = {};
function buatChart(id, label, data, labels, color) {
    if (charts[id]) {
        charts[id].destroy();
    }

    const ctx = document.getElementById(id);
    charts[id] = new Chart(ctx, {
        type: "line",
        data: {
            labels: labels,
            datasets: [{
                label: label,
                data: data,
                borderColor: color,
                backgroundColor: color + "33",
                tension: 0.3,
                fill: true
            }]
        },
        options: {
            responsive: true,
            animation: false,
            plugins: {
                legend: { display: false }
            },
            scales: {
                x: {
                    title: {
                        display: true,
                        text: "Jumlah Data", // ← label sumbu X
                        color: "#707070",
                        font: { size: 11 }
                    }
                },
                y: {
                    beginAtZero: true,
                    title: {
                        display: true,
                        text: "Nilai " + label, // ← label sumbu Y, otomatis sesuai parameter
                        color: "#707070",
                        font: { size: 11 }
                    }
                }
            }
        }
    });
}

function showMonitoringChart(data) {
    const labels = data.map((_, i) => i + 1);

    buatChart("chart-N", "Nitrogen", data.map(d => d.nitrogen ?? 0), labels, "#4caf50");
    buatChart("chart-P", "Fosfor", data.map(d => d.phosphorus ?? 0), labels, "#2196f3");
    buatChart("chart-K", "Kalium", data.map(d => d.potassium ?? 0), labels, "#ff9800");
    buatChart("chart-suhu", "Suhu", data.map(d => d.temperature ?? 0), labels, "#f44336");
    buatChart("chart-kelembaban", "Kelembaban", data.map(d => d.humidity ?? 0), labels, "#00bcd4");
    buatChart("chart-ph", "pH", data.map(d => d.ph ?? 0), labels, "#9c27b0");
    buatChart("chart-ec", "EC", data.map(d => d.ec ?? 0), labels, "#795548");
}

// Bagian Rekomendasi

db.collection("agrolytics")
    .get()
    .then((snapshot) => {
        document.getElementById("total-rekomendasi").textContent = snapshot.size;
    });

db.collection("agrolytics").get().then(function (snapshot) {
    document.getElementById("total-rekomendasi").textContent = snapshot.size;

    var tbody = document.getElementById("tbody-rekomen");
    tbody.innerHTML = "";

    for (var i = 0; i < snapshot.docs.length; i++) {
        var doc = snapshot.docs[i];
        var d = doc.data();

        var n = d.nilai_n;
        var p = d.nilai_p;
        var k = d.nilai_k;
        var suhu = d.nilai_suhu;
        var ph = d.nilai_ph;
        var kelembaban = d.nilai_kelembaban;
        var ec = d.nilai_ec;
        var tanaman = d.name;

        var tr = document.createElement("tr");
        tr.innerHTML =
            "<td>" + (i + 1) + "</td>" +
            "<td>" + n + "</td>" +
            "<td>" + p + "</td>" +
            "<td>" + k + "</td>" +
            "<td>" + suhu + "</td>" +
            "<td>" + ph + "</td>" +
            "<td>" + kelembaban + "</td>" +
            "<td>" + ec + "</td>" +
            "<td>" + tanaman + "</td>" +
            "<td><button onclick='pilihRekomendasi(\"" + doc.id + "\")'>Pilih</button></td>";

        tbody.appendChild(tr);
    }
});

function pilihRekomendasi(id) {
    console.log("Dipilih: " + id);
}

var mapRekomen = null;
var markerRekomen = null;

function pilihRekomendasi(id) {
    db.collection("agrolytics").doc(id).get().then(function (doc) {
        var d = doc.data();

        document.getElementById("rekomen-tanaman").textContent = d.name;
        document.getElementById("rekomen-n").textContent = d.nilai_n;
        document.getElementById("rekomen-p").textContent = d.nilai_p;
        document.getElementById("rekomen-k").textContent = d.nilai_k;
        document.getElementById("rekomen-suhu").textContent = d.nilai_suhu;
        document.getElementById("rekomen-ph").textContent = d.nilai_ph;
        document.getElementById("rekomen-kelembaban").textContent = d.nilai_kelembaban;
        document.getElementById("rekomen-ec").textContent = d.nilai_ec;

        document.getElementById("detail-rekomendasi").style.display = "block";

        // ambil koordinat dari id_map "-6.800193,107.650674"
        var koordinat = d.id_map.split(",");
        var lat = parseFloat(koordinat[0]);
        var lng = parseFloat(koordinat[1]);

        setTimeout(function () {
            if (mapRekomen) {
                mapRekomen.remove();
                mapRekomen = null;
            }

            mapRekomen = L.map("map-rekomendasi").setView([lat, lng], 15);
            L.tileLayer("https://tile.openstreetmap.org/{z}/{x}/{y}.png", {
                maxZoom: 19,
                attribution: "© OpenStreetMap"
            }).addTo(mapRekomen);

            markerRekomen = L.marker([lat, lng]).addTo(mapRekomen);
            markerRekomen.bindPopup(
                "<b>" + d.name + "</b><br>Lat: " + lat + "<br>Lng: " + lng
            ).openPopup();
        }, 100);
    });
}
