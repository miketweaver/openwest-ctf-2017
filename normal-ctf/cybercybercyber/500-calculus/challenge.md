# Calculus
There are no strings on me

Before you ask, this challenges is solve-able and the binary is working EXACTLY as intended.

# Files
https://nothotdog.life/files/ee7784af829c1d4aaaab090deacbacd3/openwest_ctf.bin

# Points
500

# Hint 1
Convert the flag from leet-speak to plaintext, all lower-case, no spaces

# Hint 2
If you break on anything but the first line, you have gone too far.

# Hint 3
Here is some of the source code:
```
void print_flag(double z, double w , double i, double t){ 
    printf("%f %f %f\n", z, w, i); 
    if (t >= 4) {
        printf("flag{%d}\n\r",(int)t);// Haha, jk
        return; 
    }   
    else {
        int dzdt = w;
        int h = dzdt * 25; 
        int dwdt = 1/l2[(int)t]*( l2[(int)z]*i - l2[(int)w]*l2[(int)z]*z - l2[(int)i]*w );
        int didt = 1/l2[(int)t]*(l2[(int)i] - l2[(int)z]*i - l2[(int)w]*w );
        print_flag(t+h, z+h*dzdt, w+h*dwdt, i+h*didt);
    }   
}

int main(){
    printf("\n\r");
    if(__scanr(getchar(),getchar())) print_flag(2,4,5,1);
    printf("Nice try\n\r");
    return 132;
}
```
