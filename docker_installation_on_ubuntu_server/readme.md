# CARA INSTALL DOCKER DI UBUNTU SERVER

## SILAHKAN ANDA KUNJUNGI SITUS RESMI PTERODUCTYL
```
https://pterodactyl.io/wings/1.0/installing.html
```
Setelah itu silahkan anda copy paste perintah installing docker
```
curl -sSL https://get.docker.com/ | CHANNEL=stable bash
```
Setelah itu silahkan tunggu hingga installasinya selesai, jika sudah selesai silahkan mengaktifkan si docker.io nya:
```
sudo systemctl enable --now docker
```
setelah si docker sudah berhasil terinstall dan aktif silahkan anda cek menggunakan perintah : 
```
docker ps 
```
jika muncul seperti ini : 
```bash
 ⚡ root@DESKTOP-UO99V0J  ~/algoritma_dan_pemrograman/python_base_logic   master  docker ps 
CONTAINER ID   IMAGE                                      COMMAND                  CREATED          STATUS          PORTS                                           NAMES
```
berati docker sudah berhasil di install dan sudah running

## PERINTAH DASAR DOCKER YANG HARUS DI KETAHUI 
1. build container
```
docker compose up -d --build
```
di dalam folder yang ada file docker-compose.yml nya, jika ingin di build silahkan lakukan perintah tersebut

2. execute containernya 
```
docker exec -it (nama container) bash
```
pada excute `container` ini, disni jika kita misalkan sudah `pull registry composer` pada `container php`, maka jika kita ingin lakukan `composer` kita harus excute `container` nya terlebih dahulu

3. Melihat container yang sedang berjalan
```
docker ps 
```
docker ps adalah perintah untuk melihat container yang sedang berjalan

4. stop container yang sedang berjalan
```
docker stop (nama ontainer) 
```
5. remove container yang pernah berjalan di docker
```
docker rm (nama container)
```
fungsinya remove nama container yang pernah berjalan adalah, jika kita lupa taro folder yang berisikan docker-compose.yml nya, nah kita bisa stop container nya terlebih dahulu lalu setelah itu bisa remove nama container nya

6. perintah untuk prune atau menghilangkan volumes, (hati2 karena perintah ini benar benar menghapus volumes dan membuat kita harus pull registry nya secara ulang / download ulang)
```
docker system prune --volumes -a 
```
perintah ini benar benar untuk menghapus sampah volumes yang mungkin membuat storage kita habis

7. perintah docker melihat volumes yang sudah di pull 
```
docker volume ls
```
perintah ini untuk melihat volumes yang sudah terinstall pada docker anda

8. perintah untuk melihat detail volumes 
```
docker volume inspect (nama volumes)
```
perintah ini untuk melihat data volumes tersebut

9. perintah untuk melihat logs container 
```
docker logs (nama container)
```
perintah ini berfungsi melihat log container jika tidak mau jalan container nya

10. memeriksa network docker : 
```
docker network ls
```
untuk melihat network docker container

11. perintah untuk melihat isi container dari network tersebut
```
docker network inspect (nama network nya)
``` 
12. perintah untuk connect in container dan network nya :
```
docker network connect (nama network nya) (nama container nya)
```