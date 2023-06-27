#!/usr/bin/env python3

"""
    Localy defines datatype/structs and prints their results from a call to
    type() on each one.
"""
def print_from_type_call(p_dec: bool=False) -> None:
    # Declarations for use with the type functionality
    tup      = (0,0)
    a_list   = [0]
    dick     = {'NaMe': 0}
    a_set    = {0,2,4}
    integer  = int(1)
    fl_point = float(1.03)
    string   = "This is a string"

    t_tup      = type(tup)
    t_a_list   = type(a_list)
    t_dick     = type(dick)
    t_a_set    = type(a_set)
    t_integer  = type(integer)
    t_fl_point = type(fl_point)
    t_string   = type(string)

    print("-- list of declared types and their values --\n"
          f"tuple     : {tup},\n"
          f"list      : {a_list}\n"
          f"dictionary: {dick}\n"
          f"set       : {a_set}\n"
          f"integer   : {integer}\n"
          f"fl_point  : {fl_point}\n"
          f"string    : {string}")

    print("\n-- list of declared types and their values --\n"
          f"tuple     : {t_tup},\n"
          f"list      : {t_a_list}\n"
          f"dictionary: {t_dick}\n"
          f"set       : {t_a_set}\n"
          f"integer   : {t_integer}\n"
          f"fl_point  : {t_fl_point}\n"
          f"string    : {t_string}")

if __name__ == "__main__":
    print_from_type_call()
