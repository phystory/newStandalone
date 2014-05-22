

int integral_with_error(int start, int stop) {

  float value=0;
  float error=0;

  for (int i=start;i<stop+1;i++){
    value= value + hTDCsum->GetBinContent(i);
    error=error + (hTDCsum->GetBinError(i))**2;
  }

  error = sqrt(error);

  cout << "Integral [" << start << "," << stop << "] = " << value << " +- " << error << endl;

}
