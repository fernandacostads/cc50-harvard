def get_positive_float(prompt):
    while True:
        try:
            value = float(input(prompt))
            if value >= 0:
                return value
        except ValueError:
            pass
        print("Por favor, insira um valor não negativo válido.")

def main():
    dollars = get_positive_float("Change owed: ")
    cents = round(dollars * 100)
    coins = 0

    coin_values = [25, 10, 5, 1]

    for value in coin_values:
        coins += cents // value
        cents %= value

    print(coins)

if __name__ == "__main__":
    main()
