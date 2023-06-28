#!/usr/bin/env python3

import signal
import enum

"""
    Localy defines datatype/structs and prints their results from a call to
    type() on each one.
"""
def print_from_type_call(p_dec: bool=False) -> None:
    """
    dict() declarations not used to put in other notes later for completeness

    # dictionary definitions, gonna list the ways it takes args for basic
    # use with an iterable as the only arg. (look into the argument for
    # mapping)

    dick = {'one': 1, 'two': 2, 'three': 3}

    dick = dict(zip(['one', 'two', 'three'], [1, 2, 3]))

    dick = dict([('two', 2), ('one', 1), ('three', 3)])

    dick = dict({'three': 3, 'one': 1, 'two': 2})

    dick = dict({'one': 1, 'three': 3}, two=2)
    """

    # Declarations for use with the type functionality
    dick     = dict(one=1, two=2, three=3)
    tup      = tuple((0,0))
    a_list   = list((0,0))
    a_set    = set((0,2,4))
    integer  = int(1)
    fl_point = float(1.03)
    string   = str("This is a string")
    binary   = bin("0011001")

    sig_enum = signal.Signals
    sig_meta_enum = signal.Signals.__class__

    t_tup      = type(tup)
    t_a_list   = type(a_list)
    t_dick     = type(dick)
    t_a_set    = type(a_set)
    t_integer  = type(integer)
    t_fl_point = type(fl_point)
    t_string   = type(string)
    t_binary   = type(binary)

    t_sig_enum = type(signal.Signals)
    t_sig_meta_enum = type(sig_meta_enum)

    t_module_enum_type = type(enum)

    print("-- list of declared types and their values --\n"
          f"tuple     : {tup}\n"
          f"list      : {a_list}\n"
          f"dictionary: {dick}\n"
          f"set       : {a_set}\n"
          f"integer   : {integer}\n"
          f"fl_point  : {fl_point}\n"
          f"string    : {string}\n"
          f"sig_enum  : {sig_enum}\n"
          f"sig_meta_enum : {sig_meta_enum}\n"
          f"binary    : {binary}\n")

    print("\n-- list of declared types recieved by type() --\n"
          f"tuple     : {t_tup}\n"
          f"list      : {t_a_list}\n"
          f"dictionary: {t_dick}\n"
          f"set       : {t_a_set}\n"
          f"integer   : {t_integer}\n"
          f"fl_point  : {t_fl_point}\n"
          f"string    : {t_string}\n"
          f"sig_enum  : {t_sig_enum}\n"
          f"sig_meta_enum    : {t_sig_meta_enum}\n"
          f"module_enum_type : {t_module_enum_type}")

if __name__ == "__main__":
    print_from_type_call()
