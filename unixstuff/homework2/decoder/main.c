/**
 * Main program for testing the decoder
 */
#include <stdio.h>
#include "decoder.h"

/*
 * Main
 */
int main()
{
  const char *encoded="xTt+&D+k+cDtwSSD9tc9SkxtS9kx9+PwDxPcS+ttkTtkSx9+k+&&wT+&TSSwT9DDSTkkSk9ScSSc9cT9+SSkSx9x9+T++ctS+TS+wwTwS&STStkTt9c+SDTt&Sc9xcDP+D9&D&S&t+k9TkT+w+&+TkSxSS+&&wx++Tx&&SStT&9TTTk9&9ct9c+w&TcttPT+w+PwTTTPct&t+TTk9+9cTTx9cTwST&DkS&t+tS&&t+TwSk+++9+9ctSw&TwSTT9w++&STkT+w+9S9x++TPcT+9STSSw+D+TTx9+9ckD+9xcT+++9Sk+St+&SDk+Sk+x+St+TtDDTS9wSS&SStDc9&DD9D9++S&SS9xSwtxPwcTxT+w&+tSxSx+TxD&+D&SD9++wT+DTxTxSS+9+9wxtkxTkPt&t+9+tkTtkxT+St+&c+&+DDcwS&STtc9cS9STTktT9S+TkTt9c+w&kxSSwxtkT++DDSD&STSt9+twc+STSS+kPwxxk9S+D&S&ttx&9+twSSDk9c&T&&twtxxSS+&kwtxkcD&TTxtcT9Sw+STkDT9STT+SSS9+Dwx++Dk+&DSTSx";

  char decoded[1000];

  decoder(encoded, decoded, sizeof(decoded));
  printf("%s\n", decoded);

  return 0;
}

