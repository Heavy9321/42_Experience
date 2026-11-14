# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_count_harvest_recursive.py                     :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: kasen <kasen@student.42istanbul.com.tr>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/11/13 16:37:39 by kasen           #+#    #+#               #
#  Updated: 2026/11/14 17:02:57 by kasen           ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def ft_count_harvest_recursive():
    a = int(input("Days until harvest: "))

    def count_day(day):
        if (day > a):
            return
        print("Day", day)
        count_day(day + 1)
    count_day(1)
    print("Harvest time!")
