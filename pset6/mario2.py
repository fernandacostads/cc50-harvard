def get_height():
    while True:
        try:
            height = int(input("Height: "))
            if 1 <= height <= 8:
                return height
        except ValueError:
            pass
        print("Por favor, insira um número inteiro positivo entre 1 e 8.")

def main():
    height = get_height()

    for i in range(1, height + 1):
        spaces = height - i
        hashes = i
        print(" " * spaces, end="")
        print("#" * hashes, end="  ")  # Two spaces between the pyramids
        print("#" * hashes)

if __name__ == "__main__":
    main()
