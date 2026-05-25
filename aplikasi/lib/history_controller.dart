import 'package:get/get.dart';

class HistoryController extends GetxController {
  var historyList = <Map<String, String>>[].obs;

  void addHistory(String title, String desc) {
    historyList.insert(0, {
      "title": title,
      "desc": desc,
      "date": DateTime.now().toString().substring(0, 16),
    });
  }
}