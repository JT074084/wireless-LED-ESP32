import requests

ESP32_IP = "192.168.4.1"

def send_signal(state):
    url = f"http://{ESP32_IP}/lightState?light={state}"
    print(f"Sending GET request to: {url}")

    try:
        response = requests.get(url)
        print("Response from ESP32:", response.text)
    except Exception as e:
        print("Error sending request:", e)

def main():
    print("Enter \"On\" or \"Off\" to control the LED. Enter \"q\" to exit program.")
    while True:
        light_state = input("Enter: ")
        if light_state.lower() == "q":
            break
        try:
            state = light_state.lower()
            if state == "on" or state == "off":
                send_signal(state)
            else:
                raise ValueError
        except ValueError:
            print("Enter a valid \"On\" or \"Off\" state")

if __name__ == "__main__":
    main()