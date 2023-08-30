/*
 * An example of the TOML config thing
 */

#include "__generated.hpp"
#include <cstdio>
#include <cstdlib>

int main()
{
  const ChalkydriConfig *config = chalkydri_config();

  printf("fls: %x\nfrs: %x\nbls: %x\nbrs: %x\n", config->motors.fls, config->motors.frs, config->motors.bls, config->motors.brs);

  return 0;
}

