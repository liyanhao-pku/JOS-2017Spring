#include <inc/lib.h>

// Waits until 'envid' exits.
int
wait(envid_t envid)
{
	const volatile struct Env *e;
	e = &envs[ENVX(envid)];
	while (e->env_id == envid && e->env_status != ENV_FREE)
		sys_yield();
	return e->returncode;
}
