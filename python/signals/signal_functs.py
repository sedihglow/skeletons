#!/usr/bin/env python3

import signal

def sigint_handler(signum, handler):
    print("\n\n Camera and Recording has initiated. HI\n\n")
    sys.exit(0)

def print_sigs():
    valid = signal.valid_signals()

    print("Valid Signals:")
    for sig in valid:
        cell_type = type(sig)

        #if (cell_type ==
        """
        print(f"-- valid_signals() list element values and type --\n"
              f"data element type: {cell_type}\n"
              f"sig_name: {}\n"
              f"sig_num : {}")
        """
def print_sig_sigs_enum():
    print("Members of signal.Signals:")
    for member in signal.Signals:
        print(f"{member.name} = {member.value}")

def print_sigs_meta_enum():
    meta = signal.Signals.__class__

def print_valid_sigs(pretty: bool) -> None:
    print(type(signal.valid_signals()))

if __name__ == "__main__":
    print_sigs()
