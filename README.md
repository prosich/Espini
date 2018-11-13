# Espini

- Libreria básica para inicializar NodeMCU

- Combina todas las operaciones de inicio necesarias en el NodeMCU.
     - Inicia consola a 74880 (concidente con arranque NodeMCU)
     - Conecta a WiFi.
     - Actualiza soft. si es necesario.
     - Configura syslog remoto

- Necesita un servidor http que al recibir la petición OTA 
  /espota?ser=...&app=...&ver=...:
     - Decida si es necesaria la actualización
     - Si lo es, vuelque el firmware (".bin") usando algo así:
       ```
       echo "Content-type: application/octet-stream"
       echo "Content-Length: $(wc -c $fich)"
       echo "Content-Transfer-Encoding: binary"
       echo "Content-Disposition: attachment; filename=$fich"
       echo ""
       cat $fich
       ```
           
- Necesita un servidor syslog.

- Ejemplo de uso recomendado: https://github.com/prosich/demoEspini
     
