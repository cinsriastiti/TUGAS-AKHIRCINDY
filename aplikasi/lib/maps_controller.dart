import 'package:get/get.dart';
import 'package:google_maps_flutter/google_maps_flutter.dart';
import 'package:geolocator/geolocator.dart';

class MapsController extends GetxController {
  final Rx<LatLng> currentPosition = const LatLng(0, 0).obs;
  final Rx<LatLng?> pickedPosition = Rx<LatLng?>(null);

  GoogleMapController? mapController;
  final RxSet<Marker> markerSet = <Marker>{}.obs;

  @override
  void onInit() {
    super.onInit();
    _initLocation();
  }

  Future<void> _initLocation() async {
    bool serviceEnabled = await Geolocator.isLocationServiceEnabled();
    if (!serviceEnabled) {
      await Geolocator.openLocationSettings();
      return;
    }

    LocationPermission permission = await Geolocator.checkPermission();

    if (permission == LocationPermission.denied) {
      permission = await Geolocator.requestPermission();
      if (permission == LocationPermission.denied) return;
    }

    if (permission == LocationPermission.deniedForever) {
      return;
    }

    Position pos = await Geolocator.getCurrentPosition(
      desiredAccuracy: LocationAccuracy.high,
    );

    currentPosition.value = LatLng(pos.latitude, pos.longitude);
    _updateMarker();

    mapController?.animateCamera(CameraUpdate.newLatLng(currentPosition.value));

    Geolocator.getPositionStream(
      locationSettings: const LocationSettings(
        accuracy: LocationAccuracy.high,
        distanceFilter: 30,
      ),
    ).listen((p) {
      currentPosition.value = LatLng(p.latitude, p.longitude);
      _updateMarker();
      mapController?.animateCamera(
        CameraUpdate.newLatLng(currentPosition.value),
      );
    });
  }

  void onMapCreated(GoogleMapController controller) {
    mapController = controller;
    _updateMarker();
  }

  void onTap(LatLng pos) {
    pickedPosition.value = pos;
    _updateMarker();
  }

  void _updateMarker() {
    markerSet.clear();
    markerSet.add(
      Marker(
        markerId: MarkerId("marker"),
        position: pickedPosition.value ?? currentPosition.value,
      ),
    );
  }
}
