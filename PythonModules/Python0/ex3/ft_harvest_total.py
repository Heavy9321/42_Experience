# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_harvest_total.py                               :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: kasen <kasen@student.42istanbul.com.tr>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/11/13 15:02:02 by kasen           #+#    #+#               #
#  Updated: 2026/11/13 15:06:36 by kasen           ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def ft_harvest_total():
    a = int(input("Day 1 harvest: "))
    b = int(input("Day 2 harvest: "))
    c = int(input("Day 3 harvest: "))
    print("Total harvest:", a + b + c)
