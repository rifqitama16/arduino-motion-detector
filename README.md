# arduino-motion-detector
<i>Arduino wireless motion detector with MySQL database</i>

### Disclaimer:
Ini adalah proyek lama (2 tahun lalu lebih saat repositori ini dibuat) sehingga ada kemungkinan beberapa hal sudah tidak sesuai lagi dengan saat ini.

<gambar 1>

## Deskripsi
Menggunakan 3 komponen utama yaitu Arduino Uno, ESP8266 Wifi Module, dan PIR Motion Sensor. Jika PIR mendeteksi adanya gerakan, maka PIR akan mengirim sinyal high ke Arduino dan selanjutnya Arduino akan mengirim serangkaian perintah dan data bahwa terdapat ada atau tidaknya gerakan ke ESP8266. Perintah-perintah yang diperoleh ESP8266 dari Arduino secara berurutan yaitu: membuat koneksi dengan jaringan lokal, membuat koneksi TCP ke host aldebaran.esy.es (sudah tidak aktif lagi), dan mengirim data dan mengakses file `addData.php` melalui method GET.

## Penjelasan Tiap File
File `addData.php` digunakan untuk menambahkan data log ke database. Lebih tepatnya, menginputkan nilai (dari selector motionornot) ke kolom motion yang ada pada tabel t1. File ini akan diakses tiap kali ada gerakan terdeteksi atau gerakan sudah tidak terdeteksi lagi. File `dataReview.php` digunakan untuk mendapatkan log dari database dan menampilkannya. File `WiFi_Motion_Detector_v1.ino` merupakan file utama yang nantinya diunggah ke Arduino. File `dbconnect.php` digunakan untuk melakukan koneksi ke MySQL yang di-hosting di aldebaran.esy.es. Sedangkan file `AT Command TCP.txt` adalah catatan tambahan mengenai command yang digunakan di ESP8266.

<gambar web>

## Perkabelan
Arduino > ESP8266 Wifi Module
3V3 > VCC dan CH_PD
TX > RX
RX > TX
GND > GND

Arduino > PIR Motion Sensor
5V > VCC
D3 > OUT
GND > GND

<gambar skematik>
