# NightShift - свободная реализация сервера управления Астра Дозор

## План разработки

* 0.9 - реализация MQTT-клиента с поддержкой TLS и сертификатов
* 0.9.5 - вынос конфигурации в отдельный файл
* 1.0 - daemonize и логирование в syslog/отдельный файл

## Wishlist
* фильтрация по ID устройства (события от других устройств не расшифровываются и игнорируются, команды не выполняются)