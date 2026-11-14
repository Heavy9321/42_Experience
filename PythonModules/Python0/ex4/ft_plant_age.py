# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_plant_age.py                                   :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: kasen <kasen@student.42istanbul.com.tr>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/11/13 15:07:32 by kasen           #+#    #+#               #
#  Updated: 2026/11/13 15:11:50 by kasen           ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def ft_plant_age():
    a = int(input("Enter plant age in days: "))
    if (a > 60):
        print("Plant is ready to harvest!")
    else:
        print("Plant needs more time to grow.")
