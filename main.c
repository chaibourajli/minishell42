/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MAIN.C                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbourajl <cbourajl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 13:45:52 by cbourajl          #+#    #+#             */
/*   Updated: 2022/09/03 14:26:13 by cbourajl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void){
    char *str; //the return of readline is the one to be parsed.
    while (1)
    {
        str = readline("\033[1;32mMinishell$");
    }
}