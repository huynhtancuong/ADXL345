#ifndef ADXL345_H_
#define ADXL345_H_

/**
 * ADDRESSES OF REGISTERS
*/
#define ADXL345_ADDR (0x53)
#define ADXL345_DATAX0 (0x32) // Hexadecima address for the DATAX0 internal register.
#define ADXL345_POWER (0x2D) // Power Control Register

class ADXL345 {
    private:
        const int sensitivity = 256; // (LSB/g) Sensitivity at +-2g range 
    public:
        void    init();
        int*    read();

        // get measurement in tick (LSB)
        inline int get_LSB_x(int* a) { return *(a); }
        inline int get_LSB_y(int* a) { return *(a+1); }
        inline int get_LSB_z(int* a) { return *(a+2); }

        // get measurement in G (1G = 9.8m/s^2)
        inline float get_G_x(int* a) { return float(get_LSB_x(a))/sensitivity; }
        inline float get_G_y(int* a) { return float(get_LSB_y(a))/sensitivity; }
        inline float get_G_z(int* a) { return float(get_LSB_z(a))/sensitivity; }

        // get measurement in SI unit (m/s^2)
        inline float get_SI_x(int* a) { return get_G_x(a)*9.8067; }
        inline float get_SI_y(int* a) { return get_G_y(a)*9.8067; }
        inline float get_SI_z(int* a) { return get_G_z(a)*9.8067; }
};

#endif