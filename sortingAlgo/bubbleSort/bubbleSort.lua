local function bubbleSort(t)
    local n = #t
    for i = 1, n do
        for j = 1, n - i do
            if t[j] > t[j + 1] then
                t[j], t[j + 1] = t[j + 1], t[j]
            end
        end
    end
end

local t = { 3, 2, 1, 4, 5, 6, 7, 8, 9, 10 }
bubbleSort(t)
print(table.concat(t, ", "))