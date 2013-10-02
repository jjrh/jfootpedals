import serial
import argparse



keycodes={
    "KEY_LEFT_CTRL"   :  128 ,
    "KEY_LEFT_SHIFT"  :  129 ,
    "KEY_LEFT_ALT"    :  130 ,
    "KEY_LEFT_GUI"    :  131 ,
    "KEY_RIGHT_CTRL"  :  132 ,
    "KEY_RIGHT_SHIFT" :  133 ,
    "KEY_RIGHT_ALT"   :  134 ,
    "KEY_RIGHT_GUI"   :  135 ,
    "KEY_UP_ARROW"    :  218 ,
    "KEY_DOWN_ARROW"  :  217 ,
    "KEY_LEFT_ARROW"  :  216 ,
    "KEY_RIGHT_ARROW" :  215 ,
    "KEY_BACKSPACE"   :  178 ,
    "KEY_TAB"         :  179 ,
    "KEY_RETURN"      :  176 ,
    "KEY_ESC"         :  177 ,
    "KEY_INSERT"      :  209 ,
    "KEY_DELETE"      :  212 ,
    "KEY_PAGE_UP"     :  211 ,
    "KEY_PAGE_DOWN"   :  214 ,
    "KEY_HOME"        :  210 ,
    "KEY_END"         :  213 ,
    "KEY_CAPS_LOCK"   :  193 ,
    "KEY_F1"          :  194 ,
    "KEY_F2"          :  195 ,
    "KEY_F3"          :  196 ,
    "KEY_F4"          :  197 ,
    "KEY_F5"          :  198 ,
    "KEY_F6"          :  199 ,
    "KEY_F7"          :  200 ,
    "KEY_F8"          :  201 ,
    "KEY_F9"          :  202 ,
    "KEY_F10"         :  203 ,
    "KEY_F11"         :  204 ,
    "KEY_F12"         :  205 ,
    }


# ser = serial.Serial('/dev/ttyACM1',9600)
# ser.flushInput()
# ser.flushOutput()


# ser.write("1+128\0")
# #ser.write(bytes("58"))

# print str(ser.readline())
# print str(ser.readline())
# print str(ser.readline())
# print str(ser.readline())
# print str(ser.readline())


# ser.close()


def write_to_serial(port,keycode):
    ser = serial.Serial('/dev/ttyACM1',9600)
    ser.setTimeout(20)
    ser.flushInput()
    ser.flushOutput()

    to_write = "%s+%s\0" % (port,keycode)

    ser.write(to_write)

    print ser.readline(),


    
    


if __name__ == '__main__':
    parser = argparse.ArgumentParser()

    parser.add_argument("--port","-p", type=int,help="Which input to reassign")
    parser.add_argument("--keycode","-k", help="Keycode")
    args = parser.parse_args()

    write_to_serial(args.port,args.keycode)


    
