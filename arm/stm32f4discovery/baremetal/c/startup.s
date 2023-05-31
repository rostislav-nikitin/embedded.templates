.global _statrup
_MyApp:
	LDR sp, =stack_top
	BL copy_data
	BL main
	B .
