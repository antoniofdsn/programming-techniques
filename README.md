# programming-techniques
Programming Techniques class


### Project Name: Customer Management System

## Description: 
This program is designed to manage customer data, providing options for adding new customers, removing customers, updating customer purchase amounts, displaying customer purchase amounts, displaying all customers, and displaying the customer with the highest purchase amount. The program stores customer data in memory, allowing the user to perform various operations on the data.

## Libraries:

stdio.h
stdlib.h
string.h
locale.h

## Data Structures:

Struct "Cliente" with attributes:
"nome" (string)
"ano_nascimento" (integer)
"montante_compras" (float)

## Functions:

incluir_cliente() - adds a new customer to the system
buscar_cliente() - searches for a customer in the system
remover_cliente() - removes a customer from the system
atualizar_montante_compras() - updates the purchase amount of a customer in the system
exibir_montante_compras_cliente() - displays the purchase amount of a specific customer in the system
zerar_montantes_compras() - resets the purchase amounts of all customers in the system
exibir_todos_clientes() - displays all customers in the system
cliente_melhor_comprador() - finds the customer with the highest purchase amount in the system

## Other Functions:

main() - controls the user interface and calls the appropriate functions based on the user's input.

## Constants:

MAX_INPUT - maximum length of user input
BLOCO_CLIENTES - the number of customers added to the system in each block
MAX_NOME - maximum length of the customer's name

-------------------------------------------------------------------------------------------------------------

### Project Name: Vehicle Manager.

## Description: 
The project consists of a vehicle management system that allows the user to register new vehicles and list all registered vehicles. The user can filter the list of vehicles by model, year of manufacture, and starting from a year of manufacture. In addition, the system validates the license plate of the registered vehicle to ensure that it is in the correct format.

## Technologies used: 
C programming language, 
standard language libraries (stdio.h, string.h, ctype.h, locale.h, bool.h).

## Functionalities:

Registration of new vehicles;
Listing of all registered vehicles, sorted by year of manufacture;
Filtering of vehicle list by model;
Filtering of vehicle list by year of manufacture;
Filtering of vehicle list starting from a year of manufacture;
Validation of the license plate of the registered vehicle.
