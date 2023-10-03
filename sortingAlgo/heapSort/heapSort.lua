local function heapSort(t)
    local n = #t
    local function heapify(t, n, i)
        local largest = i
        local l = 2 * i
        local r = 2 * i + 1
        if l <= n and t[l] > t[largest] then
            largest = l
        end
        if r <= n and t[r] > t[largest] then
            largest = r
        end
        if largest ~= i then
            t[i], t[largest] = t[largest], t[i]
            heapify(t, n, largest)
        end
    end
    for i = math.floor(n / 2), 1, -1 do
        heapify(t, n, i)
    end
    for i = n, 2, -1 do
        t[1], t[i] = t[i], t[1]
        heapify(t, i - 1, 1)
    end
end

local t = { 3, 2, 1, 4, 5, 6, 7, 8, 9, 10 }
heapSort(t)
print(table.concat(t, ", "))