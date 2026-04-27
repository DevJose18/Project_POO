/*
Utilizare la siguiente nomenclatura:

	-Utilizare camelCase para mis variables
	-Mis parametros en funciones no tendran ningun tipo de nomenclatura extra
	-Mis funciones siempre empezaran con la accion a hacer y despues a donde se lo voy a aplicar

*/

#include <iostream>
#include <vector>

class Capsule
{
private:
	std::string Name;
	//Healing = 1, Ki Recover = 2
	std::string Type;
	int Duration;

public:

	Capsule(std::string capsuleName, int capsuleType, int capsuleDuration)
	{
		Name = capsuleName;

		switch (capsuleType)
		{
		case 1:
			Type = "Healing";
			break;
		case 2:
			Type = "Energy";
		default:
			Type = "Unknown";
			break;
		}
		Duration = capsuleDuration;
	}

	//This is only to prints the properties of the capsule
	void ShowData()
	{
		std::cout << "Capsule: " << Name + "\n";
		std::cout << "Type: " << Type << "\n";
		std::cout << "Duration: " << Duration << "s" << "\n";
	}

	void GetInventoryData()
	{
		std::cout << "Capsule: " << Name + "\n";
		std::cout << "Type: " << Type << "\n";
		std::cout << "Duration: " << Duration << "s" << "\n";
		std::cout << "----------------------------------------------\n";
	}
	//This returns the name of the capsule referenced
	std::string GetCapsuleName()
	{
		return Name;
	}
	//This function returns the type of capsule
	std::string GetCapsuleType()
	{
		return Type;
	}
};

class Character
{
private:

	//Main properties
	int Life;
	int Ki;
	//Combat properties
	int Stamina;
	//Secondary properties
	std::vector<Capsule> inventory;

public:
	//Constructor that initializes the variable playerName
	Character(int initiallife, int initialKi, int initialStamina)
	{
		//Main properties
		Life = initialKi;
		Ki = initialKi;
		Stamina = initialKi;
	}

	//Adds the object at the beginning of the vector
	void AddToInventory(Capsule item)
	{
		inventory.push_back(item);
	}

	//Method that shows in console all the items inside of the vector
	void Showinventory()
	{
		if (inventory.size() < 1)
		{
			system("cls");
			std::cout << "You dont have any item in your inventory" << std::endl;
			std::cout << "PRESS ENTER TO GO BACK TO THE MENU" << std::endl;
		}
		else
		{
			system("cls");
			for (int i = 0; i < inventory.size(); i++)
			{
				inventory[i].GetInventoryData();
			}
			std::cout << "PRESS ENTER TO GO BACK TO THE MENU" << std::endl;
		}
		std::cin.get();
		system("cls");
	}

	//Gets the vectors size
	int GetInventorySize()
	{
		return inventory.size();
	}

	//This method increases stamina value every time is called
	void RecoverStamina()
	{
		if (Stamina != 4)
		{
			Stamina = Stamina + 1;
		}
	}

	//This method decreases Dodge value every time is called for game narrative
	void Dodge()
	{   
		if (Stamina >= 2)
		{
			Stamina = Stamina - 2;
		}
	}

	//This method prints into the console the value of Stamina and returns its value too;
	int GetStamina()
	{
		std::cout << "Stamina: " << Stamina << "\n";

		return Stamina;
	}

	//This method helps me to decrease Lifes Value
	void LoseLife(int Value)
	{
		if (Value > Life)
		{
			Value = Life;
		}
		
		Life = Life - Value;

		std::cout << "Life left: " << Life << "\n";
	}

	//This method prints Lifes Value into the console
	void PrintLife()
	{
		std::cout << "Life: " << Life << "\n";;
	}

	//This method gives to me the value of Life
	int GetLife()
	{
		return Life;
	}

	//This method helps me to decrease the value of Ki
	void LoseKi(int Value)
	{
		if (Value <= Ki)
		{
			Ki = Ki - Value;
		}
		
	}
	//This method prints in the console the value of Ki
	void PrintKi()
	{
		std::cout << "Ki: " << Ki << "\n";
	}

	//This method helps to me to control the value of Ki to increase it
	void RecoverKi(int Value)
	{
		Ki = Ki + Value;    
	}


	//This method gives to me the value of Ki
	int GetKi()
	{
		return Ki;
	}

};

int main()
{
    return 0;
}