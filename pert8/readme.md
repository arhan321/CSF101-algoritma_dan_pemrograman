# PERT 8 TUGAS NYA DAFTAR GITHUB
## WAJIB DAFTAR GITHUB SEBAGAI CALON PROGRAMER

### STEP BY STEP REGISTER GITHUB
silahkan kunjungi link
```
https://github.com/
```
setelah itu silahkan register

setelah melakukan register silahkan login

setelah login github akun di website github, silahkan anda login github nya di visual studio code

setelah login di visual studio code, silahkan semua code c++ yang pernah anda buat / bikin push ke github

setelah itu silahkan anda download git bash di windows anda, link download : 

https://shared.djncloud.my.id/git_installer_windows/

jika suemua hal di atas sudah di lakukan maka bisa ke step selanjutnya : 
### LANGKAH LANGKAH PUSH GITHUB
Pada terminal anda ke folder yang akan anda push dan silahkan anda ketikan : 
```
git init
```
setelah muncul : 
```bash
hint: Using 'master' as the name for the initial branch. This default branch name
hint: is subject to change. To configure the initial branch name to use in all
hint: of your new repositories, which will suppress this warning, call:
hint: 
hint:   git config --global init.defaultBranch <name>
hint: 
hint: Names commonly chosen instead of 'master' are 'main', 'trunk' and
hint: 'development'. The just-created branch can be renamed via this command:
hint: 
hint:   git branch -m <name>
Initialized empty Git repository in /root/contoh_push/.git/
```
berati itu tandanya git nya sudah ada di folder tersebut, setelah itu silahkan anda membuat repository pada website github dengan nama contoh : contoh_push

setelah itu silahkan anda push dengan melakukan perintah, ketikan pada terminal anda : 
```bash
git remote add origin https://github.com/arhan321/contoh_push
```
setelah sudah di lakukan remote repository, silahkan ketikan (ini supaya file nya termuat semua ready ke push): 
```bash
git add . 
```
langkah selanjutnya silahkan anda ketikan (tambahkan pesan commit): 
```bash
git commit -m "first commit"
```
jika sudah muncul tanda seperti ini : 
```bash
 ⚡ root@DESKTOP-UO99V0J  ~/contoh_push   master ✚  git commit -m "first commit"
[master (root-commit) 95c1edf] first commit
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 test.cc
```
maka anda sudha berhasil create pesan pada commit nya

langkah selanjutnya anda atur branch nya : 
```bash
git branch -m master
```
langkah selanjutnya silahkan anda melakukan push : 
```bash
git push -u origin master
```
kalo sudah ada balikan seperti ini : 
```bash
 ⚡ root@DESKTOP-UO99V0J  ~/contoh_push   master  git push -u origin master
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Writing objects: 100% (3/3), 205 bytes | 205.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
To https://github.com/arhan321/contoh_push
 * [new branch]      master -> master
branch 'master' set up to track 'origin/master'.
```
maka push anda berhasil


# TUGAS ALGORITMA DAN PEMROGRAMAN