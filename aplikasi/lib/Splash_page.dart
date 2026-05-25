import 'package:flutter/material.dart';
import 'package:flutter_application_ble/home_page.dart';


// ini itu halaman utamanya, wajib diisi. Biar bisa dipanggil dengan SplashPage
// pakai StatefulWidget karena ada perubahan halaman dan UI harus update
class SplashPage extends StatefulWidget {
  const SplashPage({super.key});

  @override
  State<SplashPage> createState() => _SplashPageState();
}

class _SplashPageState extends State<SplashPage> {
  int currentPage = 0;

  // untuk mengontrol si pageViewnya, intinya untuk pindah halaman 
  final PageController _controller = PageController();

  List<String> splashText = ["Welcome to AgroLytics", "Solusi cerdas untuk monitoring tanah dan rekomendasi tanaman yang paling cocok dengan tanah anda!"];

  // ini UI utamanya 
  // scafold itu untuk tata letak visualnya 
  // safe area itu untuk biar ga ketabrak sama status barnya 
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.white,
      body: SafeArea(
        child: Column(
          children: [

            // ini untuk bagian atasnya, ambilnya 3 bagian layar
            // pageviwnya untuk swipe kiri dan kanan nantinya, karena swipe otomatis dia update si current pagenya 
            Expanded(
              flex: 3,
              child: PageView.builder(
                controller: _controller,
                onPageChanged: (value) {
                  setState(() {
                    currentPage = value;
                  });
                },
                itemCount: splashText.length,
                itemBuilder: (context, index) =>
                // tiap halaman pakai desain dari splash content, kaya fungsi dia, biar ga ngulang terus buatnya 
                    SplashContent(text: splashText[index]),
              ),
            ),

            // ini untuk dot dot dan buttonnya 
            Expanded(
              flex: 2,
              child: Padding(
                padding: const EdgeInsets.symmetric(horizontal: 20),
                child: Column(
                  mainAxisAlignment: MainAxisAlignment.center,
                  children: [
                    // nah disini tu untuk bikin dotnya sesuai jumlah halamannya, 2
                    Row(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: List.generate(
                        splashText.length,
                        (index) => buildDot(index),
                      ),
                    ),

                    const SizedBox(height: 30),

                    /// ini untuk botton si nextnya 
                    ElevatedButton(
                      onPressed: () {
                        // ini untuk logikanya kalau dihalaman terakhir
                        if (currentPage == splashText.length - 1) {
                          Navigator.pushReplacement(
                            context,
                            MaterialPageRoute(
                              builder: (context) => const HomePage(),
                            ),
                          );
                        } else {
                          _controller.nextPage(
                            duration: const Duration(milliseconds: 400),
                            curve: Curves.ease,
                          );
                        }
                      },
                      style: ElevatedButton.styleFrom(
                        backgroundColor: const Color.fromARGB(255, 104, 145, 90),
                        minimumSize: const Size(double.infinity, 50),
                        shape: RoundedRectangleBorder(
                          borderRadius: BorderRadius.circular(16),
                        ),
                      ),
                      child: Text(
                        currentPage == splashText.length - 1
                            ? "Mulai"
                            : "Lanjut",
                        style: const TextStyle(color: Colors.white),
                      ),
                    ),
                  ],
                ),
              ),
            ),
          ],
        ),
      ),
    );
  }

  // ini untuk efek anilasi karena si animatedcontainernya 
  AnimatedContainer buildDot(int index) {
    return AnimatedContainer(
      duration: const Duration(milliseconds: 300),
      margin: const EdgeInsets.only(right: 5),
      height: 6,
      width: currentPage == index ? 20 : 6,
      decoration: BoxDecoration(
        color: currentPage == index
            ? const Color.fromARGB(255, 104, 145, 90)
            : const Color(0xFFD8D8D8),
        borderRadius: BorderRadius.circular(3),
      ),
    );
  }
}

// ini untuk isi tiap halamanny
// pakai statelless, karena hanya tampilkan data, ga berubah sendiri
class SplashContent extends StatelessWidget {
  const SplashContent({super.key, required this.text});

  final String text;

  @override
  Widget build(BuildContext context) {
    // ini isi dari semua datanya
    return Center(
      child: Column(
        mainAxisAlignment: MainAxisAlignment.center, 
        children: [
          /// Nama Aplikasi yg atas
          const Text(
            "AgroLytics",
            style: TextStyle(
              fontSize: 28,
              color: Colors.black,
              fontWeight: FontWeight.bold,
            ),
          ),

          const SizedBox(height: 10),
        // deskripsinay ini 
          Text(
            text,
            textAlign: TextAlign.center,
          ),

          const SizedBox(height: 30),
          Image.asset(
            "assets/logo.png",
            height: 300, // 🔥 bisa kamu ubah (150 - 220 aman)
          ),
        ],
      ),
    );
  }
}