#!/usr/bin/env python3

"""
xinput stuff for now

testing and stuff for xinput to develop kill_input to be used in smile



THIS CODE IS NOT LEGIT :D Probably doesnt even do anything. just got a random
spew out that pointed me in the direction of xinput

-- likely writing a version of this in bashy land

"""

import subprocess
if __name__ == "__main__":

# Define the input device ID (obtained from `xinput` command)
device_id = "YOUR_DEVICE_ID"

# Define the key to enable/disable inputs (e.g., F12)
key_to_toggle = "F12"

def disable_inputs():
    subprocess.run(["xinput", "float", device_id])

def enable_inputs():
    subprocess.run(["xinput", "reattach", device_id])

def toggle_inputs():
    is_enabled = True
    while True:
        key = input("Press {} to toggle inputs: ".format(key_to_toggle))
        if key == key_to_toggle:
            if is_enabled:
                disable_inputs()
                print("Inputs disabled")
            else:
                enable_inputs()
                print("Inputs enabled"
