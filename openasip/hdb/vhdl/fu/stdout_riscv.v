

module printchar_always_1 #(
  dataw=8
) (
  input t1data[dataw-1:0];
  input t1load;
  input t2data;
  input t2load;
  output o1data;
  input glock;
  input clk;
  input rstx;
)
synthesis translate_off
  f = $fopen("hdl_sim_stdout.txt","w");

  always@(posedge clk, t1load, glock)
  begin
    if (clk & t1load and ~glock)
      $write(f, "%d\n", t1data);
  end

  assign o1data = 1'b0;
synthesis translate_on

endmodule
