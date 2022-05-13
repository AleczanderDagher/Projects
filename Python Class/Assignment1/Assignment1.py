firstName = input("Enter your first name: ");
lastName = input("Enter your last name: ");
honorific = input("Do you prefer 'Mr', 'Ms' or 'Mrs'?: ");
length = int(input("Enter length of your rectangle: "));
width = int(input("Enter width of your rectangle: "));
area = length * width;
print("Hello", firstName, "the length and width you entered were", length, "and", width);
print(honorific, lastName, "the area is", area);
