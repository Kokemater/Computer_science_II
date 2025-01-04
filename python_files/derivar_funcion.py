from sympy import symbols, diff, sympify

def derivar_funcion(funcion_str, variable_str):
    """
    Calcula la derivada analítica de una función dada como string respecto a una variable.
    
    Args:
        funcion_str (str): La función a derivar como cadena, por ejemplo: "x**2 + sin(x)".
        variable_str (str): La variable respecto a la cual se desea derivar, por ejemplo: "x".
    
    Returns:
        sympy.Expr: La derivada simbólica de la función.
    """
    # Definir la variable simbólica
    var = symbols(variable_str)
    
    # Convertir la función de string a expresión simbólica
    funcion = sympify(funcion_str)
    
    # Calcular la derivada
    derivada = diff(funcion, var)
    
    return derivada

# Ejemplo de uso
if __name__ == "__main__":
    # Definir la función y la variable
    funcion = input("Introduce la función (por ejemplo, x**2 + sin(x)): ")
    variable = input("Introduce la variable (por ejemplo, x): ")
    
    derivada = derivar_funcion(funcion, variable)
    print(f"La derivada de {funcion} respecto a {variable} es:")
    print(derivada)

