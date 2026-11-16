# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_garden_security.py                             :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: kasen <kasen@student.42istanbul.com.tr>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/11/16 15:20:25 by kasen           #+#    #+#               #
#  Updated: 2026/11/16 23:07:42 by kasen           ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    def __init__(self, name, height, days):
        self.name = name
        self._height = height
        self._age = days

    def show(self):
        b = self.name
        print(f"Plant Created: {b}: {self._height}cm, {self._age} days old")

    def get_height(self):
        return self._height

    def set_height(self, new_height):
        if (new_height < 0):
            print(f"{self.name}: Error, height can't be negative")
            print("Height update rejected")
        else:
            self._height = float(new_height)
            print(f"Height updated: {self._height}")

    def get_age(self):
        return self._age

    def set_age(self, new_age):
        if (new_age < 0):
            print(f"{self.name}: Error, age can't be negative")
            print("Age update rejected")
        else:
            self._age = new_age
            print(f"Age updated: {self._age}")


if __name__ == "__main__":
    print("=== Garden Security System ===")
    plant = Plant("Rose", 15, 10)
    plant.show()
    print()
    en_age = plant.get_age()
    en_height = plant.get_height()
    plant.set_height(25)
    plant.set_age(30)
    print()
    plant.set_height(-5)
    plant.set_age(-5)
    print()
    plant.show()
