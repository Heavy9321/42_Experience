# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_plant_growth.py                                :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: kasen <kasen@student.42istanbul.com.tr>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/11/15 17:16:26 by kasen           #+#    #+#               #
#  Updated: 2026/11/15 21:14:16 by kasen           ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    def __init__(self, name, height, days):
        self.name = name
        self.height = height
        self.days = days

    def age(self):
        self.days += 1

    def grow(self):
        self.height = round(self.height + 0.8, 1)

    def show(self):
        print(f"{self.name}: {self.height}cm, {self.days} days old")


if __name__ == "__main__":
    plant1 = Plant("Rose", 25, 30)
    print("=== Garden Plant Growth ===")
    plant1.show()
    tmp = plant1.height
    day_start = 1
    for day_start in range(1, 8):
        print(f"=== Day {day_start} ===")
        plant1.grow()
        plant1.age()
        plant1.show()
    tmp = round(plant1.height - tmp, 1)
    print("Growth this week:", tmp)
