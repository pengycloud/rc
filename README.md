# Malrc4
This is a simple malware that uses RC4 encryption to encrypt the contents of a file with the specified key and rewrites the file with the encrypted bytes.
After that, the file can be returned by running it again with the filename and the key used to encrypt it.
## Build
```
git clone https://github.com/pengycloud/malrc4.git
cd malrc4
gcc rc4.c -o rc4
```
## Usage
`./rc4 <file> <key>`
Note: 
## Example
Compiling it.\
![](https://github.com/pengycloud/malrc4/blob/main/screenshots/gcc.png)<br><br>
Test for encryption and decryption.<br>
![](https://github.com/pengycloud/malrc4/blob/main/screenshots/test.png)
## ⚠️Disclaimer
### This is for Educational purposes only!
