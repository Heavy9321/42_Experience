# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_count_harvest_iterative.py                     :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: kasen <kasen@student.42istanbul.com.tr>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/11/14 16:33:43 by kasen           #+#    #+#               #
#  Updated: 2026/11/14 17:03:38 by kasen           ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def ft_count_harvest_iterative():
    a = int(input("Days until harvest: "))
    for b in range(1, a + 1):
        print("Day", b)
    print("Harvest time!")
