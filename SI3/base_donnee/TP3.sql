-- 1 RECURSIVITE

-- 1.1

with recursive hierarchie(employee,manager) as
	(select employee_id,manager_id
	from employees
	where manager_id is not null
	union
	select employees.employee_id,hierarchie.manager
	from employees join hierarchie
	on employees.manager_id=hierarchie.employee)

select employee,manager
from hierarchie


-- 2.1

with recursive hierarchie(employee,manager) as
	(select employee_id,manager_id
	from employees
	where manager_id is not null
	union
	select employees.employee_id,hierarchie.manager
	from employees join hierarchie
	on employees.manager_id=hierarchie.employee)

select employees.last_name, managers.last_name
from hierarchie
join employees on (employees.employee_id=hierarchie.employee)
join employees as managers on (managers.employee_id=hierarchie.manager)
order by employee


-- 3.1

with recursive hierarchie(employee,manager,distance) as
	(select employee_id,manager_id,1
	from employees
	where manager_id is not null
	union
	select employees.employee_id,hierarchie.manager,distance+1
	from employees join hierarchie
	on employees.manager_id=hierarchie.employee)

select employees.last_name, managers.last_name,distance
from hierarchie
join employees on (employees.employee_id=hierarchie.employee)
join employees as managers on (managers.employee_id=hierarchie.manager)
order by employee


-- 4.1


-- 2 STATISTIQUE

-- 2.1

SELECT 
  regions.region_name,
  countries.country_name, 
  locations.city,
  count(distinct departments.department_id) as "Nombre de départements",
  count(employees.department_id) as "Effectif total"
FROM 
  public.countries, 
  public.departments, 
  public.employees, 
  public.locations, 
  public.regions
WHERE 
  countries.country_id = locations.country_id AND
  countries.region_id = regions.region_id AND
  employees.department_id = departments.department_id AND
  locations.location_id = departments.location_id
GROUP BY 
	regions.region_name,countries.country_name,locations.city
ORDER BY 1

-- 2.2

SELECT 
  regions.region_name,
  countries.country_name, 
  locations.city,
  count(distinct departments.department_id) as "Nombre de départements",
  count(employees.department_id) as "Effectif total"
FROM 
  public.countries, 
  public.departments, 
  public.employees, 
  public.locations, 
  public.regions
WHERE 
  countries.country_id = locations.country_id AND
  countries.region_id = regions.region_id AND
  employees.department_id = departments.department_id AND
  locations.location_id = departments.location_id
GROUP BY GROUPING SETS
	((regions.region_name),
	(regions.region_name,countries.country_name),
	(regions.region_name,countries.country_name,locations.city),
	())
ORDER BY 1

-- 2.3

SELECT 
  COALESCE(regions.region_name,'Toutes les regions'),
  COALESCE(countries.country_name,'Tout les pays'), 
  COALESCE(locations.city,'Toutes les villes'),
  count(distinct departments.department_id) as "Nombre de départements",
  count(employees.department_id) as "Effectif total"
FROM 
  public.countries, 
  public.departments, 
  public.employees, 
  public.locations, 
  public.regions
WHERE 
  countries.country_id = locations.country_id AND
  countries.region_id = regions.region_id AND
  employees.department_id = departments.department_id AND
  locations.location_id = departments.location_id
GROUP BY GROUPING SETS
	((regions.region_name),
	(regions.region_name,countries.country_name),
	(regions.region_name,countries.country_name,locations.city),
	())
ORDER BY 1

-- 2.4

SELECT 
  COALESCE(regions.region_name,'Toutes les regions'),
  COALESCE(countries.country_name,'Tout les pays'), 
  COALESCE(locations.city,'Toutes les villes'),
  count(distinct departments.department_id) as "Nombre de départements",
  STRING_AGG(DISTINCT departments.department_name,' - ') ,
  count(employees.department_id) as "Effectif total"
FROM 
  public.countries, 
  public.departments, 
  public.employees, 
  public.locations, 
  public.regions
WHERE 
  countries.country_id = locations.country_id AND
  countries.region_id = regions.region_id AND
  employees.department_id = departments.department_id AND
  locations.location_id = departments.location_id
GROUP BY GROUPING SETS
	((regions.region_name),
	(regions.region_name,countries.country_name),
	(regions.region_name,countries.country_name,locations.city),
	())
ORDER BY 1

-- 2.5

-- 3 TRIGGERS

-- 3.1



