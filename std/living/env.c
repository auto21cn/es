//#pragma save_binary

 mapping env_var;

mixed query_env(string env);

int env_exists(string var)
{
	if( !env_var ) env_var = allocate_mapping(10);
	if( undefinedp(env_var[var]) ) return 0;
	return 1;
}

int setenv(string env, mixed value)
{
	int exist;

	exist = env_exists(env);
	if( !value ) value = "";
    env_var[env] = value;
    return exist;
}

int set_env(string env, mixed value)
{
	return setenv(env, value);
}

mixed getenv(string env)
{
	if( !env_exists(env) ) return 0;
	return env_var[env];
}

mixed query_env(string env)
{
	return getenv(env);
}

int remove_env(string env)
{
	if( !env_exists(env) ) return 0;
	map_delete(env_var, env);
	return 1;
}

string *regexp_query_env(string pattern)
{
	string *vars, *env;

	vars = keys(env_var);
	vars -= ({ 0 }); /* may as well skip all the "deleted" ones for now */
	env = regexp(vars, pattern);
	if( !env ) env = ({});
	return env;
}
