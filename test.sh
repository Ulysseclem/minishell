#!/bin/bash

# Test Script for Running Bash Commands in Minishell

# Start Minishell
./minishell <<EOF
>
exep: syntax error near unexpected token 'newline'

>>
exep: syntax error near unexpected token 'newline'

>>>
exep: syntax error near unexpected token '>'

>>>>
exep: syntax error near unexpected token '>>'

<
exep: syntax error near unexpected token 'newline'

<<
exep: syntax error near unexpected token 'newline'

<<<
exep: syntax error near unexpected token 'newline'

<<<<
exep: syntax error near unexpected token '<'

<<<<<
exep: syntax error near unexpected token '<<'

# Exit Minishell
exit

EOF