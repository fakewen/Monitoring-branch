
        package javax.wukong.virtualwuclasses;

            public class GENERATEDWKPF {
        public static final short ENUM_THRESHOLD_OPERATOR_LT = 0;
public static final short ENUM_THRESHOLD_OPERATOR_GT = 1;
public static final short ENUM_THRESHOLD_OPERATOR_LTE = 2;
public static final short ENUM_THRESHOLD_OPERATOR_GTE = 3;
public static final short ENUM_LOGICAL_OPERATOR_AND = 0;
public static final short ENUM_LOGICAL_OPERATOR_OR = 1;
public static final short ENUM_LOGICAL_OPERATOR_NOT = 2;
public static final short ENUM_LOGICAL_OPERATOR_XOR = 3;
public static final short ENUM_MATH_OPERATOR_MAX = 0;
public static final short ENUM_MATH_OPERATOR_MIN = 1;
public static final short ENUM_MATH_OPERATOR_AVG = 2;
public static final short ENUM_MATH_OPERATOR_ADD = 3;
public static final short ENUM_MATH_OPERATOR_SUB = 4;
public static final short ENUM_MATH_OPERATOR_MULTIPLY = 5;
public static final short ENUM_MATH_OPERATOR_DIVIDE = 6;
public static final short ENUM_PIN_PIN1 = 0;
public static final short ENUM_PIN_PIN2 = 1;
public static final short WUCLASS_THRESHOLD = 1;
public static final byte PROPERTY_THRESHOLD_OPERATOR = 0;
public static final byte PROPERTY_THRESHOLD_THRESHOLD = 1;
public static final byte PROPERTY_THRESHOLD_VALUE = 2;
public static final byte PROPERTY_THRESHOLD_OUTPUT = 3;

public static final short WUCLASS_AND_GATE = 2;
public static final byte PROPERTY_AND_GATE_INPUT1 = 0;
public static final byte PROPERTY_AND_GATE_INPUT2 = 1;
public static final byte PROPERTY_AND_GATE_OUTPUT = 2;

public static final short WUCLASS_OR_GATE = 3;
public static final byte PROPERTY_OR_GATE_INPUT1 = 0;
public static final byte PROPERTY_OR_GATE_INPUT2 = 1;
public static final byte PROPERTY_OR_GATE_OUTPUT = 2;

public static final short WUCLASS_XOR_GATE = 4;
public static final byte PROPERTY_XOR_GATE_INPUT1 = 0;
public static final byte PROPERTY_XOR_GATE_INPUT2 = 1;
public static final byte PROPERTY_XOR_GATE_OUTPUT = 2;

public static final short WUCLASS_NOT_GATE = 5;
public static final byte PROPERTY_NOT_GATE_INPUT = 0;
public static final byte PROPERTY_NOT_GATE_OUTPUT = 1;

public static final short WUCLASS_IF_SHORT = 6;
public static final byte PROPERTY_IF_SHORT_CONDITION = 0;
public static final byte PROPERTY_IF_SHORT_IF_TRUE = 1;
public static final byte PROPERTY_IF_SHORT_IF_FALSE = 2;
public static final byte PROPERTY_IF_SHORT_OUTPUT = 3;

public static final short WUCLASS_IF_BOOLEAN = 7;
public static final byte PROPERTY_IF_BOOLEAN_CONDITION = 0;
public static final byte PROPERTY_IF_BOOLEAN_IF_TRUE = 1;
public static final byte PROPERTY_IF_BOOLEAN_IF_FALSE = 2;
public static final byte PROPERTY_IF_BOOLEAN_OUTPUT = 3;

public static final short WUCLASS_CONDITION_SELECTOR_BOOLEAN = 8;
public static final byte PROPERTY_CONDITION_SELECTOR_BOOLEAN_INPUT = 0;
public static final byte PROPERTY_CONDITION_SELECTOR_BOOLEAN_CONTROL = 1;
public static final byte PROPERTY_CONDITION_SELECTOR_BOOLEAN_OUTPUT1 = 2;
public static final byte PROPERTY_CONDITION_SELECTOR_BOOLEAN_OUTPUT2 = 3;

public static final short WUCLASS_CONDITION_SELECTOR_SHORT = 9;
public static final byte PROPERTY_CONDITION_SELECTOR_SHORT_INPUT = 0;
public static final byte PROPERTY_CONDITION_SELECTOR_SHORT_CONTROL = 1;
public static final byte PROPERTY_CONDITION_SELECTOR_SHORT_OUTPUT1 = 2;
public static final byte PROPERTY_CONDITION_SELECTOR_SHORT_OUTPUT2 = 3;

public static final short WUCLASS_MATH_OP = 10;
public static final byte PROPERTY_MATH_OP_INPUT1 = 0;
public static final byte PROPERTY_MATH_OP_INPUT2 = 1;
public static final byte PROPERTY_MATH_OP_OPERATOR = 2;
public static final byte PROPERTY_MATH_OP_OUTPUT = 3;
public static final byte PROPERTY_MATH_OP_REMAINDER = 4;

public static final short WUCLASS_SERVER = 44;
public static final byte PROPERTY_SERVER_INPUT = 0;

public static final short WUCLASS_MULTIPLEXER = 46;
public static final byte PROPERTY_MULTIPLEXER_SELECTOR = 0;
public static final byte PROPERTY_MULTIPLEXER_INPUT1 = 1;
public static final byte PROPERTY_MULTIPLEXER_INPUT2 = 2;
public static final byte PROPERTY_MULTIPLEXER_CURRENT_SRC = 3;
public static final byte PROPERTY_MULTIPLEXER_CURRENT_DEST = 4;
public static final byte PROPERTY_MULTIPLEXER_ID = 5;
public static final byte PROPERTY_MULTIPLEXER_OUTPUT = 6;

public static final short WUCLASS_LIGHT_SENSOR = 1001;
public static final byte PROPERTY_LIGHT_SENSOR_CURRENT_VALUE = 0;
public static final byte PROPERTY_LIGHT_SENSOR_REFRESH_RATE = 1;

public static final short WUCLASS_PIR_SENSOR = 1003;
public static final byte PROPERTY_PIR_SENSOR_CURRENT_VALUE = 0;
public static final byte PROPERTY_PIR_SENSOR_REFRESH_RATE = 1;

public static final short WUCLASS_BINARY_SENSOR = 1004;
public static final byte PROPERTY_BINARY_SENSOR_CURRENT_VALUE = 0;
public static final byte PROPERTY_BINARY_SENSOR_REFRESH_RATE = 1;

public static final short WUCLASS_TEMPERATURE_HUMIDITY_SENSOR = 1005;
public static final byte PROPERTY_TEMPERATURE_HUMIDITY_SENSOR_CURRENT_VALUE_TEMPERATURE = 0;
public static final byte PROPERTY_TEMPERATURE_HUMIDITY_SENSOR_CURRENT_VALUE_HUMIDITY = 1;
public static final byte PROPERTY_TEMPERATURE_HUMIDITY_SENSOR_REFRESH_RATE = 2;

public static final short WUCLASS_SLIDER = 1006;
public static final byte PROPERTY_SLIDER_LOW_VALUE = 0;
public static final byte PROPERTY_SLIDER_HIGH_VALUE = 1;
public static final byte PROPERTY_SLIDER_OUTPUT = 2;
public static final byte PROPERTY_SLIDER_REFRESH_RATE = 3;

public static final short WUCLASS_MAGNETIC_SENSOR = 1007;
public static final byte PROPERTY_MAGNETIC_SENSOR_OUTPUT = 0;
public static final byte PROPERTY_MAGNETIC_SENSOR_REFRESH_RATE = 1;
public static final byte PROPERTY_MAGNETIC_SENSOR___PIN = 2;

public static final short WUCLASS_PRESSURE_SENSOR_0 = 1008;
public static final byte PROPERTY_PRESSURE_SENSOR_0_REFRESH_RATE = 0;
public static final byte PROPERTY_PRESSURE_SENSOR_0_OUTPUT = 1;
public static final byte PROPERTY_PRESSURE_SENSOR_0_HIGH = 2;
public static final byte PROPERTY_PRESSURE_SENSOR_0_LOW = 3;

public static final short WUCLASS_GH_SENSOR = 1009;
public static final byte PROPERTY_GH_SENSOR_ENABLE = 0;
public static final byte PROPERTY_GH_SENSOR_REFRESH_RATE = 1;

public static final short WUCLASS_LIGHT_ACTUATOR = 2001;
public static final byte PROPERTY_LIGHT_ACTUATOR_ON_OFF = 0;

public static final short WUCLASS_LED = 2002;
public static final byte PROPERTY_LED_REFRESH_RATE = 0;
public static final byte PROPERTY_LED_PORT1 = 1;
public static final byte PROPERTY_LED_PORT2 = 2;
public static final byte PROPERTY_LED_PORT3 = 3;
public static final byte PROPERTY_LED_PORT4 = 4;

public static final short WUCLASS_FAN = 2003;
public static final byte PROPERTY_FAN_ON_OFF = 0;

public static final short WUCLASS_IR_SENSOR = 2005;
public static final byte PROPERTY_IR_SENSOR_SIGNAL = 0;
public static final byte PROPERTY_IR_SENSOR_REFRESH_RATE = 1;

public static final short WUCLASS_ULTRASOUND_SENSOR = 2004;
public static final byte PROPERTY_ULTRASOUND_SENSOR_SIGNAL = 0;
public static final byte PROPERTY_ULTRASOUND_SENSOR_REFRESH_RATE = 1;


        }
        