# 🔐 Cryptography Demystified  
**Classical Cryptographic Algorithms in C++**

## 📌 Overview

**Cryptography Demystified** is a C++ console-based application that demonstrates the **practical implementation of classical cryptographic algorithms**. The project is designed to simplify cryptography concepts by translating theory into working code, making it suitable for academic learning, security fundamentals, and portfolio demonstration.

The application provides a **menu-driven interface** that allows users to encrypt plaintext using different classical encryption techniques and store the results in output files for further analysis.

---

## 🧠 Implemented Algorithms

- **Caesar Cipher** – Shift-based substitution cipher  
- **Rail Fence Cipher** – Zig-zag transposition cipher  
- **Vigenère Cipher** – Polyalphabetic substitution using a keyword  
- **Vernam Cipher** – XOR-based symmetric encryption model  
- **Row Transposition Cipher** – Column-based rearrangement using numeric keys  

Each algorithm is implemented using custom logic without external cryptographic libraries.

---

## ⚙️ Technical Details

- **Language:** C++  
- **Concepts Used:**  
  - Cryptographic algorithms  
  - File handling (`fstream`)  
  - Menu-driven program design  
  - String manipulation  
  - Modular function implementation  
- **Platform:** Windows  
- **Compiler:** GCC / MinGW  

---

## 📂 Project Structure

```
├── compain.cpp                      # Main source code
├── compain.exe                      # Windows executable
├── cipher.txt                       # Cipher output
├── encryption.txt                   # Encryption logs
├── rail_fence_encryption.txt
├── vigenere_encryption.txt
├── vernam_cipher_encryption.txt
├── row_transposition_encryption.txt
├── words.txt                        # Sample input text
```

---

## ▶️ How to Run

### Run (Windows):
```bash
compain.exe
```

### Compile Manually:
```bash
g++ compain.cpp -o compain
```

---

## 🎯 Learning Outcomes

- Understanding classical cryptographic techniques  
- Difference between substitution and transposition ciphers  
- Secure algorithm implementation in C++  
- File-based encryption output handling  

---

## 🚀 Future Enhancements

- Add decryption functionality  
- Implement modern cryptography (AES, RSA)  
- Cross-platform compatibility  
- GUI or web-based interface  

---

## 👨‍💻 Author

**Umer**  
Cybersecurity | Cryptography | C++ | Secure Systems  

---

## 📜 License

This project is intended for **educational purposes only**.
