import serial
import time

# Configurer le port série
arduino = serial.Serial(port='/dev/ttyACM0', baudrate=38400, timeout=1)  # Remplacez 'COM3' par le port série de votre Arduino
time.sleep(2)  # Pause pour laisser le port série s'initialiser

def send_data(data):
    if arduino.isOpen():
        # Convertir le tableau en chaîne séparée par des virgules
        data_str = ','.join(map(str, data)) + '\n'
        arduino.write(data_str.encode())  # Envoyer les données encodées
        print(f"Données envoyées : {data_str}")
    else:
        print("Le port série est fermé !")

# Exemple : Envoi d'angles pour deux moteurs
data_to_send = [-900, 120]  # Par exemple, 90° pour le moteur 1 et 120° pour le moteur 2
send_data(data_to_send)

arduino.close()