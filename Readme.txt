在使用前需要安装库  
MD_Parola
MD_MAX72xx

特别重要的时候需要修改硬件类型，
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
以及选择硬件接口模式，一般采用模拟SPI接口
// Hardware SPI connection
//MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// Arbitrary output pins
MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);
以及特别注意对应的管脚。