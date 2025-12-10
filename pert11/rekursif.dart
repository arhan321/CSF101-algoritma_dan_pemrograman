import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      home: Scaffold(
        appBar: AppBar(title: const Text("Contoh Rekursif Makanan")),
        body: Padding(
          padding: const EdgeInsets.all(16.0),
          child: CategoryWidget(
            category: makananData, // Panggil function rekursif dengan data makanan
          ),
        ),
      ),
    );
  }
}

// --------------------------------------------------------------
// MODEL KATEGORI
// --------------------------------------------------------------
class Category {
  String name;
  List<Category> children;

  Category(this.name, [this.children = const []]);
}

// --------------------------------------------------------------
// DATA MAKANAN (HIERARKI) - INI KONTEKS REKURSIFNYA
// --------------------------------------------------------------
final Category makananData = Category("Menu Makanan", [
  Category("Makanan Berat", [
    Category("Nasi Goreng"),
    Category("Mie Ayam"),
    Category("Ayam Geprek"),
  ]),
  Category("Makanan Ringan", [
    Category("Kentang Goreng"),
    Category("Risoles"),
    Category("Tahu Crispy"),
  ]),
  Category("Minuman", [
    Category("Dingin", [
      Category("Es Teh Manis"),
      Category("Es Jeruk"),
      Category("Es Kopi Susu"),
    ]),
    Category("Panas", [
      Category("Teh Tawar Hangat"),
      Category("Kopi Hitam"),
      Category("Cappuccino"),
    ]),
  ]),
]);

// --------------------------------------------------------------
// WIDGET REKURSIF
// --------------------------------------------------------------
class CategoryWidget extends StatelessWidget {
  final Category category;
  final double indent;

  const CategoryWidget({
    super.key,
    required this.category,
    this.indent = 0,
  });

  @override
  Widget build(BuildContext context) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.start,
      children: [
        Padding(
          padding: EdgeInsets.only(left: indent),
          child: Text(
            category.name,
            style: TextStyle(
              fontSize: indent == 0 ? 22 : 18,       // Judul lebih besar
              fontWeight: indent == 0 ? FontWeight.bold : FontWeight.normal,
            ),
          ),
        ),
        const SizedBox(height: 4),

        // PEMANGGILAN REKURSIF
        ...category.children.map(
          (child) => CategoryWidget(
            category: child,
            indent: indent + 20, // semakin dalam -> semakin ke kanan
          ),
        ),
      ],
    );
  }
}
