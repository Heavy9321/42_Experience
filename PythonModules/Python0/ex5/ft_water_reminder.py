# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_water_reminder.py                              :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: kasen <kasen@student.42istanbul.com.tr>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/11/13 15:12:21 by kasen           #+#    #+#               #
#  Updated: 2026/11/13 15:52:53 by kasen           ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def ft_water_reminder():
    a = int(input("Days since last watering: "))
    if (a > 2):
        print("Water the plants!")
    else:
        print("Plants are fine")
