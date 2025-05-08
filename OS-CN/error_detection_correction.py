def generate_parity_bit(data):
    count = data.count('1')
    return '0' if count % 2 == 0 else '1'


def detect_parity_error(sent_data, received_data):
    return generate_parity_bit(sent_data) != generate_parity_bit(received_data)


def perform_parity_check():
    sent_data = input("Enter sent data (binary): ")
    parity_bit = generate_parity_bit(sent_data)
    print("Parity Bit:", parity_bit)

    received_data = input("Enter received data (binary): ")
    is_error = detect_parity_error(sent_data, received_data)
    print("Error Detected!" if is_error else "No Error Detected.")


def perform_crc_division(data, generator):
    extended_data = data + '0' * (len(generator) - 1)
    data_array = list(extended_data)
    generator_array = list(generator)

    for i in range(len(data_array) - len(generator_array) + 1):
        if data_array[i] == '1':
            for j in range(len(generator_array)):
                data_array[i + j] = str(int(data_array[i + j]) ^ int(generator_array[j]))

    remainder = ''.join(data_array[-(len(generator) - 1):])
    return remainder


def detect_crc_error(sent_data, received_data, crc_result):
    return received_data != sent_data + crc_result


def perform_crc_check():
    sent_data = input("Enter sent data (binary): ")
    generator = input("Enter generator polynomial (binary): ")

    crc_result = perform_crc_division(sent_data, generator)
    print("CRC:", crc_result)

    received_data = input("Enter received data (binary): ")
    is_error = detect_crc_error(sent_data, received_data, crc_result)
    print("Error Detected!" if is_error else "No Error Detected.")


def correct_hamming_code(received_code):
    n = len(received_code)
    r = 0
    while (2 ** r) < n + 1:
        r += 1

    error_pos = 0
    for i in range(r):
        pos = 2 ** i
        count = 0

        for x in range(pos - 1, n, 2 * pos):
            for y in range(x, min(x + pos, n)):
                if received_code[y] == '1':
                    count += 1

        if count % 2 != 0:
            error_pos += pos

    if error_pos > 0:
        corrected = list(received_code)
        corrected[error_pos - 1] = '0' if corrected[error_pos - 1] == '1' else '1'
        return ''.join(corrected)
    
    return received_code


def perform_hamming_code_correction():
    received_code = input("Enter received Hamming Code: ")
    result = correct_hamming_code(received_code)

    if result != received_code:
        print("Error Detected and Corrected!")
        print("Corrected Code:", result)
    else:
        print("No Error Detected.")


def main():
    while True:
        print("\n--- Error Detection and Correction ---")
        print("1. Parity Check")
        print("2. CRC (Cyclic Redundancy Check)")
        print("3. Hamming Code")
        print("4. Exit")
        choice = input("Enter your choice: ")

        if choice == '1':
            perform_parity_check()
        elif choice == '2':
            perform_crc_check()
        elif choice == '3':
            perform_hamming_code_correction()
        elif choice == '4':
            print("Exiting program...")
            break
        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    main()