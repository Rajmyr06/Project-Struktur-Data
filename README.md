# Project-Struktur-Data
Anggota Kelompok : 
1. Wasis Enggar S       ( 2300018002 )
2.  2. Rohit Raj Mayer  ( 2300018008 )
3.  3. Sigit Nurrahman  ( 2300018055 )

----------------------------------------

# README: Program Inventori Gudang

## Deskripsi Program
Program ini merupakan aplikasi sederhana berbasis konsol yang dirancang untuk mengelola data inventori gudang dan transaksi jual beli barang. Aplikasi ini mencakup fitur seperti:
- Pengelolaan data admin berbasis KTP (Nama, NIK, dan Alamat).
- Manajemen gudang dengan sistem stack untuk menyimpan data barang.
- Antrian pembeli dengan sistem queue untuk mencatat pembeli dan transaksi.
- Simpan data KTP ke file.

## Fitur Utama
1. **Data Admin (KTP):**
   - Menambahkan data admin berupa Nama, NIK, dan Alamat.
   - Menyimpan data admin ke file `data_ktp.txt`.
   - Fitur **admin sign-in** untuk memastikan hanya admin yang terdaftar dapat mengakses menu utama.

2. **Inventori Gudang:**
   - Menambahkan barang baru ke gudang (stack) dengan kode barang dan tanggal masuk.
   - Menjual barang dari gudang berdasarkan urutan paling atas (LIFO - Last In, First Out).
   - Menampilkan daftar barang di gudang.

3. **Antrian Pembeli:**
   - Mencatat pembeli dengan data Nama, NIK, jumlah barang yang ingin dibeli, dan waktu kedatangan.
   - Mengelola antrian pembeli dengan sistem queue (FIFO - First In, First Out).
   - Menampilkan daftar pembeli yang sedang mengantri.

## Struktur Data
1. **Linked List (Data Admin/KTP):**
   - Digunakan untuk menyimpan data admin yang dapat diakses saat proses sign-in.
   - Data disimpan dalam file untuk persistensi.

2. **Stack (Gudang):**
   - Data barang disimpan menggunakan struktur stack dengan pendekatan LIFO (Last In, First Out).

3. **Queue (Pembeli):**
   - Data pembeli dikelola menggunakan struktur queue dengan pendekatan FIFO (First In, First Out).

## File Output
- `data_ktp.txt`: File ini menyimpan data admin (Nama, NIK, dan Alamat).

## Cara Menggunakan
1. **Menjalankan Program:**
   - Kompilasi program menggunakan compiler C++ seperti `g++`.
     ```bash
     g++ -o inventori_gudang inventori_gudang.cpp
     ./inventori_gudang
     ```

2. **Input Data Admin:**
   - Masukkan jumlah admin (maksimal 3).
   - Input Nama, NIK, dan Alamat untuk setiap admin.

3. **Login Admin:**
   - Masukkan Nama dan NIK yang sesuai dengan data admin untuk mengakses menu inventori gudang.

4. **Menu Inventori Gudang:**
   - **1. Entri Item Barang:** Tambahkan barang ke dalam gudang.
   - **2. Catat Pembeli:** Tambahkan pembeli ke dalam antrian.
   - **3. Jual Barang:** Jual barang berdasarkan data antrian pembeli.
   - **4. Cetak Daftar Barang:** Tampilkan semua barang di gudang.
   - **5. Cetak Daftar Pembeli:** Tampilkan semua pembeli dalam antrian.
   - **6. Keluar:** Keluar dari menu inventori.

## Struktur Program
1. **Struct dan Class:**
   - `struct KTP`: Untuk menyimpan data admin.
   - `class StackBarang`: Untuk manajemen barang di gudang.
   - `class QueuePembeli`: Untuk manajemen data pembeli.

2. **Fungsi Utama:**
   - `tambahDataKTP`: Menambahkan data admin ke linked list.
   - `simpanDataKTP`: Menyimpan data admin ke file.
   - `tampilkanDataKTP`: Menampilkan data admin yang tersimpan.
   - `adminSignIn`: Proses sign-in admin.
   - `menuInventoriGudang`: Menu utama untuk pengelolaan gudang dan pembeli.

3. **Main Program:**
   - Input data admin.
   - Simpan data ke file.
   - Admin sign-in.
   - Akses menu inventori gudang.

## Teknologi yang Digunakan
- Bahasa Pemrograman: C++
- Struktur Data: Linked List, Stack, Queue
- File I/O untuk penyimpanan data.

## Penulis
Program ini dibuat untuk tujuan pembelajaran dan manajemen sederhana. Jika ada pertanyaan, silakan hubungi melalui platform diskusi terkait.


