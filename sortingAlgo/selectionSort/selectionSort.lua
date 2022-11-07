local function selectionSort(t)
    local n = #t
    for i = 1, n - 1 do
        local min = i
        for j = i + 1, n do
            if t[j] < t[min] then
                min = j
            end
        end
        t[i], t[min] = t[min], t[i]
    end
end

local t = { 3, 2, 1, 4, 5, 6, 7, 8, 9, 10 }
selectionSort(t)
print(table.concat(t, ", "))