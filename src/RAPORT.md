# Simple Docker
## Part 1. Готовый докер
##### Чтобы работала команда `docker pull` запустил команды `sudo snap install docker` и `sudo apt install docker.io`
##### Взять официальный докер образ с **nginx** и выкачать его при помощи `docker pull`
![comands](screen/1.1.png)
##### Проверить наличие докер образа через `docker images`
![comands](screen/1.2.png)
##### Запустить докер образ через `docker run -d [image_id|repository]`
![comands](screen/1.3.png)
##### Проверить, что образ запустился через `docker ps`
![comands](screen/1.4.png)
##### Посмотреть информацию о контейнере через `docker inspect [container_id|container_name]`
##### в моём случае `container_name` это `exciting_jackson`
![comands](screen/1.5.png)
##### По выводу команды определить и поместить в отчёт размер контейнера, список замапленных портов и ip контейнера
![comands](screen/1.6.png)<br>*ip контейнера*<br>
![comands](screen/1.7.png)<br>*Поскольку при запуске Docker-контейнера маппинг не был настроен, поле ключа PortBindings Docker-контейнера будет пустым*<br>
![comands](screen/1.8.png)<br>*С добавлением флага -s в отчёте повялются поля SizeRw - это размер файлов, которые были созданы или изменены, если сравнить контейнер с его базовым образом и SizeRootFs - общий размер всех файлов в контейнере в байтах*<br>
##### Остановить докер образ через `docker stop [container_id|container_name]`
![comands](screen/1.9.png)
##### Проверить, что образ остановился через `docker ps`
![comands](screen/1.10.png)
##### Запустить докер с замапленными портами 80 и 443 на локальную машину через команду *run*
![comands](screen/1.11.png)
##### Проверить, что в браузере по адресу *localhost:80* доступна стартовая страница **nginx**
![comands](screen/1.12.png)
##### Перезапустить докер контейнер через `docker restart [container_id|container_name]`
##### Проверить любым способом, что контейнер запустился
![comands](screen/1.13.png)

## Part 2. Операции с контейнером

##### Прочитать конфигурационный файл *nginx.conf* внутри докер контейнера через команду *exec*
![comands](screen/2.1.png)
##### Создать на локальной машине файл *nginx.conf*
![comands](screen/2.2.png)
##### Настроить в нем по пути */status* отдачу страницы статуса сервера **nginx**
![comands](screen/2.3.png)
##### Скопировать созданный файл *nginx.conf* внутрь докер образа через команду `docker cp`
##### Перезапустить **nginx** внутри докер образа через команду *exec*
![comands](screen/2.4.png)
##### Проверить, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**
![comands](screen/2.5.png)
##### Экспортировать контейнер в файл *container.tar* через команду *export*
##### Остановить контейнер
![comands](screen/2.6.png)
##### Удалить образ через `docker rmi [image_id|repository]`, не удаляя перед этим контейнеры
![comands](screen/2.7.png)
##### Удалить остановленный контейнер
![comands](screen/2.8.png)
##### Импортировать контейнер обратно через команду *import*
##### Запустить импортированный контейнер
![comands](screen/2.9.png)
##### Проверить, что по адресу *localhost:80/status* отдается страничка со статусом сервера **nginx**
![comands](screen/2.10.png)

## Part 3. Мини веб-сервер

##### Написать мини сервер на **C** и **FastCgi**, который будет возвращать простейшую страничку с надписью `Hello World!`
![comands](screen/3.1.png)<br>*Компилятор C*<br>
![comands](screen/3.2.png)<br>*Перенос в контейнер компилируемого файла и переход в директорию контейнера*<br>
![comands](screen/3.3.png)<br>*Обновление контейнера*<br>
![comands](screen/3.4.png)<br>*Скачивание в контейнер библиотеки FastCgi*<br>
![comands](screen/3.5.png)<br>*Скачивание компилятора gcc*<br>
![comands](screen/3.6.png)<br>*Скачивание spawn-fcgi*<br>
##### Запустить написанный мини сервер через *spawn-fcgi* на порту 8080
![comands](screen/3.7.png)
##### Написать свой *nginx.conf*, который будет проксировать все запросы с 81 порта на *127.0.0.1:8080*
![comands](screen/3.8.png)
##### Проверить, что в браузере по *localhost:81* отдается написанная вами страничка
![comands](screen/3.9.png)
##### Положить файл *nginx.conf* по пути *./nginx/nginx.conf* (это понадобится позже)
![comands](screen/3.10.png)

## Part 4. Свой докер

#### Написать свой докер образ, который:
##### 1) собирает исходники мини сервера на FastCgi из [Части 3](#part-3-мини-веб-сервер)
##### 2) запускает его на 8080 порту
##### 3) копирует внутрь образа написанный *./nginx/nginx.conf*
##### 4) запускает **nginx**.
##### Собрать написанный докер образ через `docker build` при этом указав имя и тег
![comands](screen/4.1.png)
##### Проверить через `docker images`, что все собралось корректно
![comands](screen/4.2.png)
##### Запустить собранный докер образ с маппингом 81 порта на 80 на локальной машине и маппингом папки *./nginx* внутрь контейнера по адресу, где лежат конфигурационные файлы **nginx**'а (см. [Часть 2](#part-2-операции-с-контейнером))
![comands](screen/4.3.png)
##### Проверить, что по localhost:80 доступна страничка написанного мини сервера
![comands](screen/4.4.png)
##### Дописать в *./nginx/nginx.conf* проксирование странички */status*, по которой надо отдавать статус сервера **nginx**
##### Перезапустить докер образ
##### Проверить, что теперь по *localhost:80/status* отдается страничка со статусом **nginx**
![comands](screen/4.4.png)

## Part 5. **Dockle**

`scp -P 5555 meadowse@localhost:/home/meadowse/part4/Dockerfile ~/DO5_SimpleDocker-0/src/part5/`
`brew install goodwithtech/r/dockle`
`dockle`
`docker build -t myserver:new .`
`docker images`
##### Просканировать образ из предыдущего задания через `dockle [image_id|repository]`
![comands](screen/5.1.png)
##### Исправить образ так, чтобы при проверке через **dockle** не было ошибок и предупреждений
![comands](screen/5.2.png)

## Part 6. Базовый **Docker Compose**

##### Написать файл *docker-compose.yml*, с помощью которого:
##### 1) Поднять докер контейнер из [Части 5](#part-5-инструмент-dockle) _(он должен работать в локальной сети, т.е. не нужно использовать инструкцию **EXPOSE** и мапить порты на локальную машину)_
##### 2) Поднять докер контейнер с **nginx**, который будет проксировать все запросы с 8080 порта на 81 порт первого контейнера
##### Замапить 8080 порт второго контейнера на 80 порт локальной машины
##### Остановить все запущенные контейнеры
##### Собрать и запустить проект с помощью команд `docker-compose build` и `docker-compose up`
![comands](screen/6.1.png)
##### Проверить, что в браузере по *localhost:80* отдается написанная вами страничка, как и ранее
![comands](screen/6.2.png)
![comands](screen/6.3.png)<br>*Остановить работу Docker Compose*<br>
