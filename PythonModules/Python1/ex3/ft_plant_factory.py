# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_plant_factory.py                               :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: kasen <kasen@student.42istanbul.com.tr>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/11/15 21:12:05 by kasen           #+#    #+#               #
#  Updated: 2026/11/15 21:39:44 by kasen           ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

class Plant:
    def __init__(self, name, height, days):
        self.name = name
        self.height = float(height)
        self.days = days

    def show(self):
        print(f"Created: {self.name}: {self.height}cm, {self.days} days old")


if __name__ == "__main__":
    print("=== Plant Factory Output ===")
    Rose = Plant("Rose", 25, 30)
    Oak = Plant("Oak", 200, 365)
    Cactus = Plant("Cactus", 15, 120)
    Sunflower = Plant("Sunflower", 80, 45)
    Fern = Plant("Fern", 15, 120)
    Plants = [Rose, Oak, Cactus, Sunflower, Fern]
    for plant in Plants:
        plant.show()
