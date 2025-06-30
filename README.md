
# 📌 Simulasi Mini-SOS (Sistem Operasi Sederhana)

**Oleh:** Tim Gacor
**Mata Kuliah:** Struktur Data
**Universitas:** Amikom Yogyakarta

---

## 📋 Deskripsi Proyek

Simulasi Mini-SOS adalah program berbasis C++ yang mensimulasikan fitur dasar dari sistem operasi secara sederhana. Aplikasi ini dibangun untuk memenuhi tugas akhir mata kuliah *Struktur Data* dengan menerapkan struktur data dasar dan lanjutan seperti array, struct, stack, queue, linked list, dan tree.

---

## 🎯 Tujuan

- Melatih kemampuan implementasi struktur data secara manual
- Memahami konsep manajemen proses dalam sistem operasi
- Membuat simulasi eksekusi proses secara FIFO
- Menerapkan konsep undo dan visualisasi struktur proses

---

## ✅ Kriteria Wajib

| Fitur        | Penjelasan                                 |
|--------------|---------------------------------------------|
| Array        | Menyimpan daftar proses                    |
| Struct       | Menyimpan properti proses (ID, nama, dll)  |
| Sorting      | Mengurutkan proses (burst time/prioritas)  |
| Searching    | Mencari proses berdasarkan ID/nama         |

---

## 🔼 Poin Tambahan

| Struktur Data | Implementasi                                                 |
|---------------|---------------------------------------------------------------|
| Stack         | Digunakan untuk fitur undo proses terakhir                   |
| Queue         | FIFO: simulasi eksekusi proses menggunakan circular queue    |
| Linked List   | Menyimpan proses dalam rantai node terhubung                 |
| Tree          | Menyimpan proses secara hirarkis (parent-child structure)    |

---

## 🗂️ Struktur File

| File                  | Fungsi                                                  |
|-----------------------|---------------------------------------------------------|
| `main.cpp`            | Program utama & menu interaktif                         |
| `Process.hpp`         | Struktur data `Process` dan fungsi display              |
| `ProcessManager.hpp`  | Manajemen array proses: add, sort, search, remove       |
| `StackUndo.hpp`       | Stack (array) untuk fitur undo                   |
| `QueueSimulator.hpp`  | Queue (circular array) untuk eksekusi proses     |
| `LinkedList.hpp`      | Struktur data linked list untuk proses berantai         |
| `TreeHirarki.hpp`     | Struktur tree untuk proses dengan relasi hirarki        |

---

## 🖥️ Fitur Aplikasi

- Tambah proses (dengan ID otomatis)
- Tampilkan semua proses
- Urutkan proses berdasarkan burst time atau prioritas
- Cari proses berdasarkan ID atau nama
- Simulasi eksekusi proses (dengan queue FIFO)
- Undo proses terakhir (stack)
- Visualisasi linked list proses
- Visualisasi hirarki proses dalam tree

---

## 🚀 Cara Compile

Buka terminal atau command prompt, lalu jalankan perintah berikut:

```bash
g++ main.cpp -o mini_sos
./mini_sos
```

Pastikan semua file `.hpp` berada di direktori yang sama dengan `main.cpp`.

---
