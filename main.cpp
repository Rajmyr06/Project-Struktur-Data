#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Struct untuk menyimpan data KTP
struct KTP {
    string nama;
    string nik;
    string alamat;
    KTP* next;
};

// Class untuk Stack Barang
class StackBarang {
private:
    struct Barang {
        string tanggalMasuk;
        string kode;
        Barang* next;
    };
    Barang* top;

public:
    StackBarang() : top(nullptr) {}

    void push(string kode, string tanggalMasuk) {
    Barang* newNode = new Barang();
    newNode->kode = kode;
    newNode->tanggalMasuk = tanggalMasuk;
    newNode->next = nullptr;

    if (!top) {
        top = newNode;
    } else {
        if (tanggalMasuk > top->tanggalMasuk) {
            newNode->next = top;
            top = newNode;
        } else {
            Barang* temp = top;
            while (temp->next && temp->next->tanggalMasuk >= tanggalMasuk) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}

    void pop(const string & buyerNIK) {
         if (!top) {
            cout << "Gudang kosong. Tidak ada barang yang dapat dijual.\n";
            return;
        }
        Barang* temp = top;
        cout << "Barang " << top->kode << " terjual kepada pembeli dengan NIK " << buyerNIK << "\n";
        top = top->next;
        delete temp;
    }

    void print() {
        if (!top) {
            cout << "Gudang kosong.\n";
            return;
        }
        Barang* temp = top;
        while (temp) {
            cout << "\n--- Data Barang ---\n";
            cout << "Kode Barang      : " << temp->kode << "\n";
            cout << "Tanggal Masuk    : " << temp->tanggalMasuk << "\n";
            temp = temp->next;
        }
    }
    bool isEmpty() {
        return top == nullptr;
    }
};

// Class untuk Queue Pembeli
class QueuePembeli {
public:
    struct Pembeli {
        string nik;
        string nama;
        int jumlahBarang;
        string waktuKedatangan;
        Pembeli* next;
    };
    Pembeli* front;
    Pembeli* rear;

public:
    QueuePembeli() : front(nullptr), rear(nullptr) {}

    void enqueue(string nik, string nama, int jumlahBarang, string waktuKedatangan) {
        Pembeli* newNode = new Pembeli();
        newNode->nik = nik;
        newNode->nama = nama;
        newNode->jumlahBarang = jumlahBarang;
        newNode->waktuKedatangan = waktuKedatangan;
        newNode->next = nullptr;

        if (!rear) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "\nPembeli atas nama " << nama << " dengan NIK " << nik << " berhasil dicatat.\n";
    }
    void dequeue() {
        if (!front) {
            cout << "Tidak ada pembeli dalam antrian.\n";
            return;
        }
        Pembeli* temp = front;
        front = front->next;

        if (!front) {
            rear = nullptr;
        }

        delete temp;
    }

    Pembeli* getFront() {
        return front;
    }

    void print() {
        if (!front) {
            cout << "Tidak ada pembeli dalam antrian.\n";
            return;
        }
        Pembeli* temp = front;
        while (temp) {
            cout << "\n--- Data Pembeli ---\n";
            cout << "Nama             : " << temp->nama << "\n";
            cout << "NIK              : " << temp->nik << "\n";
            cout << "Jumlah Barang    : " << temp->jumlahBarang << "\n";
            cout << "Waktu Kedatangan : " << temp->waktuKedatangan << "\n";
            temp = temp->next;
        }
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

// Pointer untuk head linked list KTP
KTP* headKTP = nullptr;

// StackBarang dan QueuePembeli sebagai objek global
StackBarang gudang;
QueuePembeli antrianPembeli;

// Fungsi untuk menambah data KTP
void tambahDataKTP(string nama, string nik, string alamat) {
    KTP* newNode = new KTP();
    newNode->nama = nama;
    newNode->nik = nik;
    newNode->alamat = alamat;
    newNode->next = nullptr;
    if (!headKTP) {
        headKTP = newNode;
    } else {
        KTP* temp = headKTP;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Fungsi untuk menyimpan data KTP ke file
void simpanDataKTP() {
    ofstream file("data_ktp.txt", ios::app);
    if (file.is_open()) {
        KTP* temp = headKTP;
        while (temp) {
            file << temp->nama << "," << temp->nik << "," << temp->alamat << "\n";
            temp = temp->next;
        }
        file.close(); // Tutup file setelah selesai menulis
        cout << "\nData KTP berhasil disimpan ke file data_ktp.txt\n";
    } else {
        cout << "\nGagal membuka file untuk menyimpan data!\n";
    }
}

// Fungsi untuk menampilkan data KTP
void tampilkanDataKTP() {
    KTP* temp = headKTP;
    while (temp) {
        cout << "\n--- Data KTP ---\n";
        cout << "Nama   : " << temp->nama << "\n";
        cout << "NIK    : " << temp->nik << "\n";
        cout << "Alamat : " << temp->alamat << "\n";
        temp = temp->next;
    }
}

// Fungsi untuk memeriksa admin sign-in
bool adminSignIn() {
    string nik, nama;
    cout << "\n--- Admin Sign-In ---\n";
    cout << "Masukkan Nama: ";
    cin >> nama;
    cin.ignore(); // Membersihkan buffer
    cout << "Masukkan NIK: ";
    getline(cin, nik);

    KTP* temp = headKTP;
    while (temp) {
        if (temp->nik == nik && temp->nama == nama) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Fungsi untuk menu inventori gudang
void menuInventoriGudang() {
    int pilihan;
    do {
        cout << "\n--- Menu Inventori Gudang ---\n";
        cout << "1. Entri Item Barang\n";
        cout << "2. Catat Pembeli\n";
        cout << "3. Jual Barang\n";
        cout << "4. Cetak Daftar Barang\n";
        cout << "5. Cetak Daftar Pembeli\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                string kode, tanggalMasuk;
                cout << "Masukkan Kode Barang: ";
                cin >> kode;
                cout << "Masukkan Tanggal Masuk (YYYY-MM-DD): ";
                cin >> tanggalMasuk;
                gudang.push(kode, tanggalMasuk);
                break;
            }
            case 2: {
                string nik, nama, waktuKedatangan;
                int jumlahBarang;

                // --- Input Data KTP Pembeli ---
                cout << "\n--- Input Data KTP Pembeli ---\n";
                cout << "Nama   : ";
                cin >> nama;
                cin.ignore();
                cout << "NIK    : ";
                getline(cin, nik);

                // --- Input Data Pembelian ---
                cout << "\n--- Input Data Pembelian ---\n";
                cout << "Jumlah Barang yang Dibeli: ";
                cin >> jumlahBarang;
                cin.ignore(); // Membersihkan buffer
                cout << "Waktu Kedatangan (HH:MM): ";
                getline(cin, waktuKedatangan);

                // Panggil fungsi catatPembeli
                antrianPembeli.enqueue(nik, nama, jumlahBarang, waktuKedatangan);
                break;
            }
            case 3: {
                if (antrianPembeli.isEmpty()) {
                    cout << "Tidak ada pembeli dalam antrian.\n";
                } else {
                   QueuePembeli::Pembeli* pembeli = antrianPembeli.getFront();
                    for (int i = 0; i < pembeli->jumlahBarang; ++i) {
                        if (!gudang.isEmpty()) {
                          gudang.pop(pembeli->nik); 
                        } else {
                            cout << "Tidak ada barang lagi di gudang untuk dijual.\n";
                            break;
                        }
                    }
                    antrianPembeli.dequeue();
                }
                break;
            }
            case 4:
                gudang.print();
                break;
            case 5:
                antrianPembeli.print();
                break;
            case 6:
                cout << "Keluar dari menu inventori.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 6);
}

int main() {
    int jumlah;
    cout << " " << endl;
    cout << " ------------------ PROGRAM INVENTORI GUDANG ------------------" << endl;
    cout << " " << endl;
    cout << "Berapa banyak data KTP untuk Admin yang ingin diinput (maks 3) : ";
    cin >> jumlah;
    if (jumlah > 3) jumlah = 3;
    cin.ignore();

    for (int i = 0; i < jumlah; ++i) {
        string nama, nik, alamat;
        cout << "\nInput Data KTP ke-" << i + 1 << ":\n";

        // Input Nama
        cout << "Nama   : ";
        getline(cin, nama);

        // Input NIK
        cout << "NIK    : ";
        cin >> nik;
        cin.ignore();

        // Input Alamat
        cout << "Alamat : ";
        getline(cin, alamat);

        tambahDataKTP(nama, nik, alamat);
    }

    simpanDataKTP();
    tampilkanDataKTP();

    bool loginSuccess = false;
    while (!loginSuccess) {
        if (adminSignIn()) {
            cout << "\nAkses diterima. Anda berhasil masuk sebagai admin.\n";
            loginSuccess = true;
            menuInventoriGudang();
        } else {
            cout << "\nAkses Ditolak. Coba Lagi? (Y/N): ";
            char choice;
            cin >> choice;
            if (choice != 'y' && choice != 'Y') {
                cout << "Anda Keluar dari program.\n";
                return 0; // Keluar dari program jika pengguna tidak ingin mencoba lagi
            }
        }
    }
    return 0;
}