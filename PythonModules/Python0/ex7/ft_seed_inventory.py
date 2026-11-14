# ************************************************************************* #
#                                                                           #
#                                                      :::      ::::::::    #
#  ft_seed_inventory.py                              :+:      :+:    :+:    #
#                                                  +:+ +:+         +:+      #
#  By: kasen <kasen@student.42istanbul.com.tr>   +#+  +:+       +#+         #
#                                              +#+#+#+#+#+   +#+            #
#  Created: 2026/11/14 17:04:23 by kasen           #+#    #+#               #
#  Updated: 2026/11/14 17:51:31 by kasen           ###   ########.fr        #
#                                                                           #
# ************************************************************************* #

def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    if (unit == "packets"):
        print(seed_type.capitalize(), "seeds:", quantity, "packets available")
    elif (unit == "grams"):
        print(seed_type.capitalize(), "seeds:", quantity, "grams total")
    else:
        b = str(seed_type.capitalize())
        print(b, "seeds: covers", quantity, "square meters")
