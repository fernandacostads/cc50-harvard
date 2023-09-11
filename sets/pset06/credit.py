def main():
    card_number = input("Number: ")
    if is_valid(card_number):
        if is_amex(card_number):
            print("AMEX")
        elif is_mastercard(card_number):
            print("MASTERCARD")
        elif is_visa(card_number):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")

def is_valid(card_number):
    if not card_number.isdigit():
        return False

    card_digits = [int(digit) for digit in card_number]
    card_digits.reverse()

    total = 0
    for i, digit in enumerate(card_digits):
        if i % 2 == 1:
            digit *= 2
            if digit > 9:
                digit -= 9
        total += digit

    return total % 10 == 0

def is_amex(card_number):
    return len(card_number) == 15 and card_number.startswith(("34", "37"))

def is_mastercard(card_number):
    return len(card_number) == 16 and card_number.startswith(("51", "52", "53", "54", "55"))

def is_visa(card_number):
    return (len(card_number) == 13 or len(card_number) == 16) and card_number.startswith("4")

if __name__ == "__main__":
    main()
