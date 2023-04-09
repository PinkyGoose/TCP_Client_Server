# clientserver

## client
В этой папке расположено консольное приложение клиента
Синтаксис его вызова: `client {имя файла}`, 
т.е. если терминал находится в директории .../clientserver/client, и мы хоЧим отправить файл RobinHood, вызов будет:
`./client RobinHood`

## server
Сервер - демон, с именем в ps/диспетчере задач serverd. 
Сохраняет получаемые файлы с оригинальным именем в директорию .../clientserver/server/files.
При отправке сигнала SIGTERM или SIGHUP завершает работу корректно, завершая передачу файлов, которые уже в процессе обработки.
Остальные сигналы обрабатываются по дефолту.

## server.log
Лог сервера, в который записывается служебная информация, в т.ч. уведомления об обработке определенных сообщений